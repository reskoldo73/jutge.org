/*
Considereu un tauler n × m amb alguns obstacles. Compteu tots els camins que
surten de la cantonada superior esquerra, arriben a la cantonada inferior dreta,
i passen exactament per sobre de k obstacles. Els únics moviments permesos són
cap avall i cap a la dreta.

Entrada

L’entrada consisteix en diversos casos. Cada cas comença amb n, m i k, seguits
d’n línies amb m ‍caràcters cadascuna. Els punts indiquen posicions lliures, i
les ‘X’ obstacles. Podeu assumir que n i m estan entre 2 i 100, i que k està
entre 0 i n + m − 1.

Sortida

Per a cada cas, escriviu el nombre de camins possibles. Com que aquest nombre
pot ser molt gros, feu els càlculs mòdul 109 + 7.
*/

//reskoldo73, 2025-10-29

#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;


const int mod = 1e9 + 7;

int n, m;
vvvi memo;
vvb mat;

int solve(int i, int j, int k) {
    if(i < 0 or j < 0 or k < 0) return 0;
    if(i == 0 and j == 0) {
        if(mat[i][j]) --k;
        return (k ? 0 : 1);
    }
    if(mat[i][j]) --k;
    if(memo[i][j][k] != -1) return memo[i][j][k];
    return memo[i][j][k] = (solve(i-1, j, k) + solve(i, j-1, k))%mod;
}

int main () {
    int k;
    while(cin >> n >> m >> k) {
        mat = vvb(n, vb(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char temp;
                cin >> temp;
                mat[i][j] = temp == 'X';           
            }
        }
        memo = vvvi(n, vvi(m, vi(k + 1, -1)));
        cout << solve(n-1, m-1, k) << "\n";
    }
}