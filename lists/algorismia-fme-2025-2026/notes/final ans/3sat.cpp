#include <iostream>
#include <vector>
using namespace std;

int backtrack(int i, int n, vector<vector<int>>& pos, vector<vector<int>>& neg, vector<bool>& satisfied, vector<int>& unassigned) {
    // Si la asignación parcial ya hace insatisfactible alguna cláusula, devuelve 0
    bool done = true;
    for (int c = 0; c < satisfied.size(); ++c)
        if (!satisfied[c]) {
            done = false;
            if (unassigned[c] == 0) return 0;
        }
    // Si ya están todas satisfechas, cuenta las asignaciones de las variables restantes
    if (done) return 1 << (n - i);
    
    // Prueba las dos asignaciones para la variable i
    int ret = 0;
    vector<vector<int>> affected = { neg[i], pos[i] };
    for (int value = 0; value < 2; ++value) {
        vector<int> newly_sat, reduced;
        for (int c : affected[value])                // cláusulas que se satisfacen con esta asignación
            if (!satisfied[c]) { newly_sat.push_back(c); satisfied[c] = true; }
        for (int c : affected[1 - value])            // cláusulas que pierden una variable
            if (!satisfied[c]) { reduced.push_back(c); --unassigned[c]; }
        ret += backtrack(i + 1, n, pos, neg, satisfied, unassigned);
        for (int c : newly_sat) satisfied[c] = false;
        for (int c : reduced) ++unassigned[c];
    }
    return ret;
}

int main() {
    int num_var, num_claus;
    while (cin >> num_var >> num_claus) {
        vector<vector<int>> pos(num_var), neg(num_var);     // para cada variable, en qué clausulas aparece el literal positivo y el negativo
        vector<bool> satisfied(num_claus, false);
        vector<int> unassigned(num_claus, 3);
        for (int i = 0; i < num_claus; ++i) {
            string clausula;
            cin >> clausula;
            for (char lit : clausula) {
                if (isupper(lit)) pos[lit - 'A'].push_back(i);
                else neg[lit - 'a'].push_back(i);
            }
        }
        cout << backtrack(0, num_var, pos, neg, satisfied, unassigned) << "\n";
    }
    return 0;
}
