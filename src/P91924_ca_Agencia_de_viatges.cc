/*
Una agència de viatges ven rutes. En particular, disposa d’𝑚 parells de ciutats connectades
amb vols directes en ambdós sentits. Una ruta és una seqüència de ciutats tal que es pot volar
directament des de cada ciutat a la següent, amb dues condicions:
• Cal fer almenys un vol.
• Les ciutats de la ruta han d’aparèixer en ordre alfabètic.
L’agència vol calcular quantes rutes pot oferir als seus clients. La podeu ajudar?
Per exemple, si tenim vols directes entre Barcelona i París, entre Barcelona i Londres, i entre
París i Londres, llavors hi ha exactament quatre rutes possibles: Barcelona → París, Barcelona
→ Londres, Barcelona → Londres → París, i Londres → París.
Entrada
L’entrada consisteix en diversos casos. Cada cas comença amb el nombre de vols entre ciutats
𝑚. Segueixen els 𝑚 vols amb el format que podeu veure als exemples. Els noms de ciutats
estan compostos només per entre 1 i 10 lletres minúscules. No hi ha vols entre una ciutat i
ella mateixa, ni vols repetits. Si anomenem 𝑛 al nombre de ciutats diferents d’un cas, podeu
suposar 2 ≤ 𝑛 ≤ 10^4, i 𝑚 ≤ 5𝑛.
Sortida
Per a cada cas, escriviu el nombre de rutes possibles. Com que aquest nombre pot ser molt
gros, feu els càlculs mòdul 10^8 + 7.
*/

//reskoldo73, 2026-01-12 Examen Final Algorismia FME 2025-2026
// 10/10

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//agencia de viatges

const int mod = 1e8+7;

using vs = vector<string>;

unordered_map<string, vs> flights;
unordered_map<string, int> memo;


int dp(string s) {
    if(memo[s] != -1) return memo[s];
    int sum = 0;
    for(string x : flights[s]) {
        sum = (1 + sum + dp(x)) % mod;
    }
    return memo[s] = sum;
}

int main () {
    int n;
    while (cin >> n) {
        flights.clear();
        for(int i = 0; i < n; ++i) {
            string a, b, trash;
            cin >> a >> trash >> b;
            //you can only travel in one direction
            if(a < b) flights[a].push_back(b);
            else flights[b].push_back(a);
        }
        memo.clear();
        for(auto x : flights) memo[x.first] = -1;
        int ans = 0;
        for(auto x : flights) {
            ans = (ans + dp(x.first)) % mod;
        }
        cout << ans << endl;
    }
}