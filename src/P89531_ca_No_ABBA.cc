/*
Considereu una paraula composta només amb ‘A’ i ‘B’. Algunes posicions tenen el
contingut fixat, mentre que d’altres podeu escollir si tenen una ‘A’ o una ‘B’.
De quantes maneres podeu triar el contingut de les posicions lliures de forma
que la subparaula “ABBA” no hi aparegui?

Entrada

L’entrada consisteix en diverses paraules amb entre 1 i 105 caràcters. Les
lletres fixades es marquen amb ‘A’ i ‘B’, mentre que les lletres per triar es
marquen amb punts.

Sortida

Per a cada paraula, escriviu el nombre de maneres de completar-la sense que hi
aparegui la subparaula “ABBA”. Com que el resultat pot ser molt gros, feu els
càlculs mòdul 108 + 7.

Pista

La solució esperada és una programació dinàmica amb 4n estats, on n és la mida
de la paraula donada.
*/

//reskoldo73, 2026-01-10

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int mod = 1e8 + 7;

vvi memo;
string s;
int n;

/*
0 free
1 a
2 ab
3 abb
*/
int dp (int i, int state);

int dpa (int i, int state) {
    if(state == 3) return 0;
    return dp(i-1, 1) % mod;
}

int dpb (int i, int state) {
    if(state == 1) return dp(i-1, 2) % mod;
    if(state == 2) return dp(i-1, 3) % mod;    
    return dp(i-1, 0) % mod;
}

int dp (int i, int state) {
    if(i < 0) return 0;
    int &temp = memo[i][state];
    if(temp != -1) return temp;

    if(s[i] == '.') {
        return temp = (dpa(i, state) + dpb(i, state) ) % mod;
    }
    else if (s[i] == 'A'){
        return temp = dpa(i, state) % mod;
    }
    else { //s[i] == 'B'
        return temp = dpb(i, state) % mod;
    }
}

int main () {
    while(cin >> s) {
        n = s.size();
        memo = vvi(n, vi(4, -1));
        memo[0] = vi(4, 1);
        if(s[0] == 'A') memo[0][3] = 0;
        else if(s[0] == '.') memo[0][0] = memo[0][1] = memo[0][2] = 2;
        cout << dp(n-1, 0) << endl;
    }
}

