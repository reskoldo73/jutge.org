/*
En un món distòpic les persones són criades en granges. Després de conviure
molts anys junts, els nens se separen en diversos grups en funció de les seves
característiques. Per reduir el trauma psicològic, la separació es realitza amb
diverses cerimònies, en cadascuna de les quals un subgrup es divideix en dos. El
cost de cada cerimònia de separació és igual al nombre de persones del grup.

Per exemple, suposeu un grup amb 30 persones, que s’ha de dividir en cinc grups
A, B, C, D i E de mides respectives 3, 9, 1, 7 i 10. En aquest cas podem
separar-los inicialment amb A, C i D d’una banda, i B i E de l’altra. Ara
separem el primer subgrup: A i C d’una banda, i D de l’altra. Després, separem A
i C. Finalment, separem B i E. El cost de totes les cerimònies és 30 + 11 + 4 +
19 = 64, que es pot demostrar que és el mínim possible.

Donada la informació de la mida final de tots els grups, podeu calcular el cost
mínim de totes les cerimònies necessàries?

Entrada

L’entrada consisteix en diversos casos, cadascun amb el nombre de grups n entre
1 i 105, seguit d’n nombres entre 1 i 109 indicant la mida de cada grup final.

Sortida

Per a cada cas, escriviu la suma mínima possible dels costs de totes les
cerimònies.
*/

//reskoldo73, 2026-01-10

#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

int main () {
    int n;
    while(cin >> n) {
        priority_queue<ll> pq;
        for(int i = 0; i < n; ++i) {
            ll temp;
            cin >> temp;
            pq.push(-temp);
        }
        ll sum = 0;
        while(pq.size() > 1) {
            ll temp1 = -pq.top(); pq.pop();
            ll temp2 = -pq.top(); pq.pop();
            ll tempsum = temp1 + temp2;
            pq.push(-tempsum);
            sum += tempsum;
        }
        cout << sum << endl;
    }


}