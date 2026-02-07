/*
Considereu un tauler n × m amb alguns obstacles. Trobeu tots els camins que
surten de la cantonada superior esquerra, arriben a la cantonada inferior dreta,
i passen exactament per sobre de k obstacles. Els únics moviments permesos són
cap avall i cap a la dreta.

Entrada

L’entrada consisteix en diversos casos. Cada cas comença amb n, m i k, seguits
d’n línies amb m ‍caràcters cadascuna. Els punts indiquen posicions lliures, i
les ‘X’ obstacles. Podeu assumir que n i m estan entre 2 i 10, i que sempre hi
haurà almenys un camí possible.

Sortida

Per a cada cas, escriviu en ordre lexicogràfic tots els camins possibles. Feu
servir ‘D’ per als moviments cap avall, i ‘R’ per als moviments cap a la dreta.
Escriviu una línia amb 10 guions després de cada cas.

Observació

La solució esperada és un backtracking senzill.
*/

//reskoldo73, 2025-10-29

#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;

int n, m, k, count;
vb ans;
vvb mat;

void print() {
    for(bool x : ans) cout << (x ? 'D' : 'R');
    cout << "\n";
}

void solve(int i, int j) {
    if(i >= n or j >= m) return;
    if(i == n-1 and j == m-1) {
        if(mat[i][j]) ++count;
        if(k == count) print();
        if(mat[i][j]) --count;
        return;
    }
    bool obs = mat[i][j];
    ans.push_back(true);
    if(obs) ++count;
    solve(i+1, j);
    if(obs) --count;
    ans.pop_back();

    ans.push_back(false);
    if(obs) ++count;
    solve(i, j+1);
    if(obs) --count;
    ans.pop_back();
}

int main () {
    while(cin >> n >> m >> k) {
        mat = vvb(n, vb(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char temp;
                cin >> temp;
                mat[i][j] = temp == 'X';           
            }
        }
        ans = vb();
        count = 0;
        solve(0, 0);
        cout << "----------\n";
    }
}