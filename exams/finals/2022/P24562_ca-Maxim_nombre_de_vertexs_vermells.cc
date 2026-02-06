/*
Feu un programa que, donat un graf no dirigit, digui si és possible pintar-ne
tots els vèrtexs només amb dos colors (vermell i blau), de manera que no hi hagi
dos vèrtexs veïns del mateix color. En cas afirmatiu, cal maximitzar el nombre
de vèrtexs de color vermell.

Entrada

L’entrada consisteix en diversos casos, cadascun amb el nombre de vèrtexs n i el
nombre d’arestes m, seguits d’m parells x y indicant una aresta entre x i y.
Suposeu 1 ≤ n ≤ 104, 0 ≤ m ≤ 5n, que els vèrtexs es numeren entre 0 i n − 1, x ≠
y, i que no hi ha més d’una aresta entre cada parell x y.

Sortida

Per a cada cas, si el graf es pot pintar amb els dos colors, escriviu “yes”
seguit del màxim nombre possible de vèrtexs vermells. Altrament, escriviu “no”.
*/

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi graf;
vi vist;
int totsum, sump, sumn;

void read(int n, int m) {
    graf = vvi(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    vist = vi(n, 0);
    totsum = 0;
}

bool dfs(int ini, int col) {
    vist[ini] = col;
    if(col < 0) ++sumn;
    else ++sump;
    bool ans = true;
    for(int i = 0; ans and i < (int)graf[ini].size(); ++i) {
        int temp = graf[ini][i];
        if(vist[temp] == col) return false;
        else if(vist[temp] == 0) ans = dfs(temp, -col);
    }
    return ans;
}

bool solve(int n) {
    for(int i = 0; i < n; ++i) {
        if(vist[i] == 0) {
            sump = sumn = 0;
            if(not dfs(i, 1)) return false;
            totsum += max(sump, sumn);
        }
    }
    return true;
}



int main () {
    int n, m;
    while(cin >> n >> m) {
        read(n, m);
        if(solve(n)) cout << "yes " << totsum << endl;
        else cout << "no" << endl;
    }   
}