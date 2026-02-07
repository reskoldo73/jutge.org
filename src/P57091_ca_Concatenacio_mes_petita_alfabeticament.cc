/*
Disposeu d’n paraules formades amb lletres minúscules. Cap de les paraules té
dues (o ‍més) lletres adjacents iguals. Heu de concatenar totes les paraules de
manera que la paraula obtinguda tampoc tingui dues lletres consecutives iguals.
Si hi ha diverses possibilitats, trieu la que sigui més petita
lexicogràficament.

Entrada

L’entrada consisteix en diversos casos, amb una n entre 1 i 10, seguida de les n
paraules. Cap paraula és un prefix d’una altra paraula.

Sortida

Per a cada cas, escriviu la paraula obtinguda, o bé “NO” si no se’n pot obtenir
cap.
*/

//reskoldo73, 2025-10-29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;

int n;
vs words;
vb avail;
vi ans;
vvb ok;
bool found;

void print() {
    for(int x : ans) cout << words[x];
    cout << "\n";
}

void solve(int k) {
    if(k == n) {
        found = true;
        return print();
    } 
    if(found) return;
    for(int i = 0; i < n; ++i) {
        if(avail[i] and (k == 0 or ok[ans[k-1]][i])) {
            avail[i] = false;
            ans[k] = i;
            solve(k+1);
            avail[i] = true;
        }
    }
}

int main () {
    while(cin >> n) {
        words = vs(n);
        for(string &s : words) cin >> s;
        ans = vi(n);
        avail = vb(n, true);
        found = false;
        sort(words.begin(), words.end());
        ok = vvb(n, vb(n, true));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ok[i][j] = words[i][words[i].size() - 1] != words[j][0];
        solve(0);
        if(not found) cout << "NO\n";
    }
}