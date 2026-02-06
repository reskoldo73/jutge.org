#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& orden, const vector<string>& pal) {
    for (int indice : orden) cout << pal[indice];
    cout << "\n";
}

bool backtrack(int i, const vector<string>& pal, vector<bool>& usada, vector<int>& orden, int pares_ig) {
    if (pares_ig >= 2) return false;
    if (i == pal.size()) {
        print(orden, pal);
        return true;
    } else {
        bool sol = false;
        for (int j = 0; j < pal.size(); ++j)
            if (!usada[j]) {
                usada[j] = true;
                int sig_pares = pares_ig + (i > 0 && pal[orden[i - 1]].back() == pal[j][0]);
                orden[i] = j;
                sol = backtrack(i + 1, pal, usada, orden, sig_pares) || sol;
                usada[j] = false;
            }
        return sol;
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> pal(n);
        for (int i = 0; i < n; ++i) cin >> pal[i];
        sort(pal.begin(), pal.end());                   // para el orden lexicográfico, si no hay prefijos

        vector<bool> usada(n);
        vector<int> orden(n);                           // índices de las palabras en el resultado
        if (!backtrack(0, pal, usada, orden, 0)) cout << "NO\n";
        cout << "----------\n";
    }
    return 0;
}
