/*
Hi ha un objecte a la part superior esquerra d’un tauler n × m. Repetidament,
l’objecte es mourà una casella a la dreta o una casella cap avall. Tanmateix, el
tauler té obstacles que fan que l’objecte s’aturi. També, hi ha caselles on
l’objecte es mourà sempre cap a la dreta, i ‍caselles on l’objecte es mourà
sempre cap avall.

Podeu escriure totes les trajectòries que fan sortir l’objecte del tauler?

Entrada

L’entrada consisteix en diversos casos. Cada cas comença amb n i m, seguides d’n
files amb m ‍caràcters cadascuna. Els punts indiquen caselles buides, les ‘D’
caselles que fan anar cap a la dreta, les ‘A’ caselles que fan anar cap avall, i
les ‘X’ obstacles. Podeu suposar que n i m són entre 1 i 10.

Sortida

Per a cada cas, escriviu en ordre alfabètic totes les trajectòries que fan que
l’objecte surti del tauler. Codifiqueu amb ‘A’ el moviments cap avall, i amb ‘D’
els moviments cap a la dreta. Escriviu una línia amb 10 guions al final de cada
cas.
*/

//reskoldo73, 2025-10-26

#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vc = vector<char>;
using vvc = vector<vc>;

vb ans;
int n, m;
vvc grid;

void print() {
    for(bool x : ans) cout << (x ? 'A' : 'D');
    cout << "\n";
}

void solve(int i, int j) {
    if(i >= n or j >= m) return print();
    char &temp = grid[i][j];
    if(temp == 'X') return;
    if(temp == 'A' or temp == '.') {
        ans.push_back(true);
        solve(i+1, j);
        ans.pop_back();
    }
    if(temp == 'D' or temp == '.') {
        ans.push_back(false);
        solve(i, j+1);
        ans.pop_back();
    }
}

int main () {
    while(cin >> n >> m) {
        grid = vvc(n, vc(m));
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j)
                cin >> grid[i][j];
        ans = vb();
        solve(0, 0);
        cout << "----------\n";
    }
}