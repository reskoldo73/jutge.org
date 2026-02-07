/*
Sigui 𝑚 un natural. Donats 𝑛 naturals, trobeu tots els parells de nombres (𝑥, 𝑦) tals que 𝑥 + 𝑦
sigui múltiple d’𝑚.

Entrada

L’entrada consisteix en diversos casos, cadascun amb un natural 𝑝 (que s’explica més avall),
una 𝑚 entre 2 i 300, una 𝑛 entre 2 i 5 ⋅ 10^4, i els 𝑛 naturals, tots diferents.

Sortida

Per a cada cas, considereu tots els parells amb suma múltiple d’𝑚. Els nombres han d’estar
ordenats dins de cada parell, i els parells han d’estar ordenats entre si (primer pel primer
nombre i, en cas d’empat, pel segon).
Com que escriure tots els parells podria ocupar massa espai, escriviu només els parells saltant
de 𝑝 en 𝑝, començant pel primer. Per exemple, amb 𝑝 = 1 cal escriure tots els parells, amb
𝑝 = 2 un de cada dos, etc.
Escriviu 10 guions al final de cada cas.

Observacions

• Els jocs de proves grossos s’han creat a l’atzar.
• La vostre solució ha de ser eficient. Amb una solució que bàsicament comprovi tots els
parells de nombres el jutge us donarà 50 punts, i podreu obtenir una nota màxima de
5 en aquest problema.
• No podeu fer servir el tipus @pair@ de C++.

Pista

Considereu el residu de cada nombre donat mòdul 𝑚.
*/

//reskoldo73, 2026-01-18

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int p, m, n;
    while(cin >> p >> m >> n) {
        vector<int> input(n);
        for(int i = 0; i < n; ++i) cin >> input[i];
        sort(input.begin(), input.end());

        vector<vector<int>> mods(m);
        for(int i = 0; i < n; ++i) {
            int temp = input[i];
            mods[temp%m].push_back(temp);
        }

        int count = 0;

        for(int i = 0; i < n; ++i) {
            int temp = input[i];
            int mod = (m - temp%m) % m;
            
            int L = 0;
            int R = mods[mod].size() - 1;
            int modend = mods[mod].size();

            while (L <= R) {
                int mid = L + (R - L) / 2;
                if (mods[mod][mid] > temp) {
                    modend = mid;
                    R = mid - 1;
                }
                else L = mid + 1;
            }

            for(int j = modend; j < (int)mods[mod].size(); ++j) {
                if(count % p == 0) cout << temp << ' ' << mods[mod][j] << "\n";
                ++count;
            } 
        }
        cout << "----------" << endl;
    }
}