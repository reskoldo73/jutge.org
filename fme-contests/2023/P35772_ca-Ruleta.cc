/*
El professor Oak s’està quedant pobre! Demà haurà de pagar un deute de y euros,
pero només en té x. Així que ha decidit jugar-s’ho tot a la ruleta! (Nens, no
jugueu a la ruleta, que és molt perillós. I no tingueu deutes que no podeu
pagar, sigueu responsables.)

El professor Oak s’ho jugarà tot a que surten parells, fins que pugui pagar el
deute, o fins que s’hagi quedat sense diners. Cada vegada, té una probabilitat
18/37 de duplicar el que hagi posat, i una probabilitat 19/37 de perdre-ho tot.

Donats x i y, quina és la probabilitat que el professor Oak pugui pagar el seu
deute?

Entrada

L’entrada consisteix en diversos casos, cadascun amb dos enters x i y entre 0 i
109.

Sortida

Per a cada cas, escriviu la probabilitat demanada amb cinc decimals. Escriviu
aquestes dues línies a l’inici del main():

    cout.setf(ios::fixed);
    cout.precision(5);
*/

#include <iostream>

using namespace std;

using ll = long long;

double dpow (ll times, double x) {
    double ans = 1;
    for(ll i = 0; i < times; ++i) ans *= x;
    return ans;
}

ll times(ll x, ll y) {
    ll ans = 0;
    while(x < y) {
        x *= 2;
        ++ans;
    }
    return ans;
}

int main () {
    cout.setf(ios::fixed);
    cout.precision(5);

    ll x, y;
    while(cin >> x >> y) {
        double zero = 0;
        if(x == 0) cout << (y ? zero : ++zero) << endl;
        else cout << dpow(times(x, y), 18/(double)37) << endl;
    }
}