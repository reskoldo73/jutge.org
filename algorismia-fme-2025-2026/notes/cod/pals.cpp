// https://jutge.org/problems/P93727_en
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graph;

void add_edge(int v, int w, Graph& G, Graph& Grev) {
    G[v].push_back(w);
    Grev[w].push_back(v);
}

void dfs(int v, const Graph& G, vector<bool>& visited, vector<int>& order) {
    visited[v] = true;
    for (int w : G[v])
        if (!visited[w]) 
            dfs(w, G, visited, order);
    order.push_back(v);
}

int main() {
    int ncases;
    cin >> ncases;
    for (int case_id = 1; case_id <= ncases; ++case_id) {
        int num_cat, num_cond;
        cin >> num_cat;
        cin.get();          // lee el fin de línea

        // Creamos una variable binaria para cada pareja (categoría, posibilidad).
        int num_vars = 0;
        map<string, int> var;
        vector<vector<int>> cat_info(num_cat);
        for (int i = 0; i < num_cat; ++i) {
            string line, possib;
            getline(cin, line);
            istringstream iss(line);
            while (iss >> possib) {
                var[possib] = num_vars;
                cat_info[i].push_back(num_vars++);
            }
        }

        // Crea un grafo dirigido con 2 * num_vars vértices; el vértice 2i representa que esta variable está a false y el 2i + 1 que está a true. Las aristas representan implicaciones.
        // Si a y b están en la misma categoría y son distintos: x[a] implica not x[b] (como mucho uno por categoría).
        int n = 2 * num_vars;
        Graph G(n), Grev(n);
        for (const auto& row : cat_info) 
            for (int a : row)
                for (int b : row)
                    if (a != b)
                        add_edge(2 * a + 1, 2 * b, G, Grev);

        // Leemos las dos opciones (a, b) de cada amigo. No elegir a implica elegir b; no elegir b implica elegir a.
        cin >> num_cond;
        for (int i = 0; i < num_cond; ++i) {
            string name, cond1, cond2;
            cin >> name >> cond1 >> cond2;
            int a = var[cond1], b = var[cond2];
            add_edge(2 * a, 2 * b + 1, G, Grev);
            add_edge(2 * b, 2 * a + 1, G, Grev);
        }

        // Hay una solución si y solo no existe una contradicción del tipo x[a] => not x[a] => x[a].
        // Es decir, si ninguna componente fuertemente conexa contiene una variable y su negación.
        vector<bool> visited(n);
        vector<int> order;
        for (int v = 0; v < n; ++v) 
            if (!visited[v])
                dfs(v, G, visited, order);

        vector<int> comp_id(n);
        int num_comps = 0;
        reverse(order.begin(), order.end());
        visited.assign(n, false);
        for (int v : order)
            if (!visited[v]) {
                vector<int> comp;
                dfs(v, Grev, visited, comp);
                for (int w : comp) 
                    comp_id[w] = num_comps;
                ++num_comps;
            }

        bool sol = true;
        for (int i = 0; sol && i < num_vars; ++i)
            if (comp_id[2 * i] == comp_id[2 * i + 1]) sol = false;
        cout << "Case #" << case_id << ": " << (sol ? "yes" : "no") << "\n";
    }
    return 0;
}
