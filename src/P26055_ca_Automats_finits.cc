/*
Un autòmat finit és un graf dirigit tal que de cadascun dels vèrtexs (anomenats estats) en
surten dos arcs (anomenades transicions), amb etiquetes 0 i 1. Hi ha un estat anomenat
inicial. A més, els estats poden ser d’acceptació o de rebuig. Per exemple, a l’autòmat

/imagen/

l’estat inicial és el 0, i hi ha un únic estat d’acceptació, el 4.
Donada una paraula amb zeros i uns, l’autòmat accepta la paraula si, des de l’estat inicial,
llegint la paraula d’esquerra a dreta i saltant d’estat a estat seguint la transició del símbol
actual, al final s’acaba en un estat d’acceptació.
Per exemple, considerem la paraula 0100: comencem al 0, amb el 0 anem a 1, amb el 1 anem
a 2, amb el 0 anem a 3, i finalment amb el 0 acabem a 4, que és d’acceptació, així que la
paraula és acceptada. En canvi, tots els prefixos de 0100 (això és, la paraula buida, 0, 01 i
010) són rebutjats, perquè després de llegir-los l’estat al que s’acaba és de rebuig. De fet,
0100 és la paraula més curta de les acceptades per aquest autòmat (que són precisament
totes les que contenen 0100).
Donat un autòmat finit, podeu determinar la paraula més curta acceptada (si n’hi ha cap)?
Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb el nombre d’estats 𝑛, els quals
es representen amb nombres entre 0 i 𝑛 − 1. A continuació vénen 𝑛 parells 𝑠0
𝑠1
, un per a
cada estat 0 ≤ 𝑖 < 𝑛, indicant una transició entre 𝑖 i 𝑠0 etiquetada amb un 0, i una transició
entre 𝑖 i 𝑠1 etiquetada amb un 1, respectivament. Finalment ve una paraula amb 𝑛 caràcters,
que indiquen per a cada estat 0, …, 𝑛 − 1 si és d’acceptació ‘A’ o de rebuig ‘R’. Assumiu
2 ≤ 𝑛 ≤ 104
, que l’estat inicial sempre és el 0, que sempre serà de rebuig, i que almenys hi
ha un estat d’acceptació.
Sortida
Per cada cas, escriviu la paraula més curta acceptada per l’autòmat. En cas d’empat, trieu la
paraula lexicogràficament més petita. Si no n’hi ha cap, escriviu “no”.
*/

//reskoldo73, 2026-01-12 Examen Final Algorismia FME 2025-2026
// 4/10 WA because I don't mark the visited nodes

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//automats finits

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;
using vpii = vector<pii>;

vvi graf;
vi vist;
vpii pare;
string ans;
int n;

void auxprint(int i) {
    string output = "";
    while(i != 0) {
        output += char('0' + pare[i].second);
        i = pare[i].first;
    }
    output += char('0' + pare[i].second);
    cout << output << endl;
}

void print(int i) {
    if(i > 0) {
        // cout << i << endl;
        // //auxprint(i);
        // for(auto x : pare) cout << x.first << ' ' << x.second << endl;
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}

void bfs() {
    vist[0] = 1;
    queue<int> q;
    q.push(0);
    while(not q.empty()) {
        int v = q.front(); q.pop();
        for(int i = 0; i < 2; ++i) {
            int temp = graf[v][i];
            if(vist[temp] == 0) {
                pare[temp] = {v, i};
                print(temp);
                return;
            } 
            else if (vist[temp] == -1) {
                pare[temp] = {v, i};
                ans += char('0' + i);
                q.push(temp);               
            }
        }            
    }
    print(-1);
}

// he trobat com saber si existeix o no, però no sé trobar la paraula concreta, 
// auxprint entra en un bucle infinit per alguna raó

//update: entra en un bucle infinit quan el fill de 1 és 1, però això no hauria de passar mai
int main () {
    while(cin >> n) {
        graf = vvi(n, vi(2));
        vist = vi(n, -1);

        for(int i = 0; i < n; ++i) {
            int zero, one;
            cin >> zero >> one;
            graf[i] = {zero, one};
        }
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i) if(s[i] == 'A') vist[i] = 0;

        pare = vpii(n);
        bfs();
    }
}