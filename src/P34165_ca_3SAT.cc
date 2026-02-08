/*
Feu un programa que compti totes les solucions d’un conjunt d’𝑚 clàusules 𝑐1
, … , 𝑐𝑚 de tres
literals en forma normal conjuntiva.
Per exemple, considereu les tres clàusules
𝑎 ∨ 𝑏 ∨ 𝑐, ¬𝑎 ∨ 𝑏 ∨ 𝑐, 𝑏 ∨ ¬𝑐 ∨ 𝑑 .
(Aquest és el primer exemple de l’entrada.) Hi ha 10 solucions possibles, una de les quals és
{𝑎 = cert, 𝑏 = fals, 𝑐 = cert, 𝑑 = cert}
Entrada
L’entrada consisteix en diversos casos, cadascun amb el nombre de variables 𝑛 i el nombre de
clàusules 𝑚, seguides de les 𝑚 clàusules. Cada clàusula es defineix amb una paraula amb tres
lletres diferents d’entre les 𝑛 primeres de l’alfabet. Les lletres majúscules indiquen variables
tal qual, i les minúscules variables negades.
Podeu suposar 3 ≤ 𝑛 ≤ 26, 1 ≤ 𝑚 ≤ 100, que les lletres dins de cada clàusula estan ordenades
entre si, que no hi ha clàusules repetides, que cada variable apareix en almenys una clàusula,
i que sempre hi haurà alguna solució.
Sortida
Per a cada cas, escriviu el nombre de solucions del conjunt de clàusules.
Pista
La solució esperada per a aquest problema és un backtracking conceptualment simple
*/

//reskoldo73, 2026-01-12 Examen Final Algorismia FME 2025-2026
// 8/10

#include <iostream>
#include <vector>

using namespace std;

//3-sat

using vb = vector <bool>;
using vs = vector<string>;

vb ans;
vs inp;
int n, m, count;

bool chartobool (int i, int j) {
    char c = inp[i][j];
    if('a' <= c and c <= 'z') return not ans[(c - 'a')];
    else return ans[(c - 'A')];
}

int chartoabs (char c) {
    if('a' <= c and c <= 'z') return c - 'a';
    else return c - 'A';
}

bool clauseok(int i, int j) {
    if(j < chartoabs(inp[i][2])) return true;
    return chartobool(i, 0) or chartobool(i, 1) or chartobool(i, 2);
}

bool solok(int j) {
    bool ok = true;
    for(int i = 0; ok and i < m; ++i) {
        ok = clauseok(i, j);
    }
    return ok;
}

void backtracking(int i) {
    if(i == n) {
        if(solok(i)) ++count;
        return;
    }
    if(not solok(i-1)) return;
    ans[i] = true;
    backtracking(i + 1);
    ans[i] = false;
    backtracking(i + 1);

}



int main () {
    while(cin >> n >> m) {
        inp = vs(m);
        for(string &x : inp) cin >> x;
        count = 0;
        ans = vb(n);
        backtracking(0);
        cout << count << endl;
    }
}