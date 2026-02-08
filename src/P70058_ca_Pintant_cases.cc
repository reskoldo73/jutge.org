/*
En un carrer hi ha 𝑛 cases. La façana de cada casa 𝑖 es pot pintar amb tres colors diferents,
amb costs respectius 𝑐1𝑖, 𝑐2𝑖 i 𝑐3𝑖. Calculeu el cost mínim de pintar totes les cases, amb una
restricció: les cases adjacents han de tenir colors diferents.
Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb 𝑛, seguida de 𝑐11, 𝑐12, …, 𝑐1𝑛,
seguits de 𝑐21, 𝑐22, …, 𝑐2𝑛, seguits de 𝑐31, 𝑐32, …, 𝑐3𝑛. Suposeu 1 ≤ 𝑛 ≤ 10^5
, i que tots els costs es troben entre 0 i 10^9.
Sortida
Per a cada cas, escriviu el cost mínim de pintar les 𝑛 façanes.
*/

//reskoldo73, 2026-01-12 Examen Final Algorismia FME 2025-2026
// 10/10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//pintant cases

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

vvll memo, costs;

ll dp (int i, int j) {
    if(i < 0 or j < 0) return 0; //just in case
    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = costs[i][j] + min(dp((i + 2)%3, j-1), dp((i+1)%3, j-1));
}

int main () {
    int n;
    while(cin >> n) {
        memo = vvll(3, vll(n, -1));
        costs = vvll(3, vll(n));
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> costs[i][j];
            }
            memo[i][0] = costs[i][0];
        }
        cout << min( min( dp(0, n-1) , dp(1, n-1) ) , dp(2, n-1) ) << endl;
    }
}