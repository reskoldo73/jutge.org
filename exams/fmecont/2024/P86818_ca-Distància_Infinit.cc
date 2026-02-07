/*
El club de “Paseíllos extremos FME” és conegut per haver arribat des de
Barcelona fins a Terrassa, Montserrat i Mataró en un sol dia (o una sola nit).
El seu gran objectiu és anar caminant fins a França, on volen visitar n llocs
d’interès. Durant la passejada debaten com de dispersos estan aquests llocs
entre si, i decideixen que una bona mètrica seria calcular la distància infinit
entre cada parell de llocs. Podeu ajudar-los?

Formalment: Donats n punts {p0, …, pn−1} amb coordenades enteres pi = (xi, yi),
cal calcular


∑ 0 ≤ i < j < n d∞(pi, pj) , on d∞(pi, pj) = max(| xi − xj |, | yi − yj |).

Entrada

L’entrada consisteix en diversos casos, cadascun amb n seguida dels n punts,
tots diferents i amb coordenades entre 0 i 109. Podeu suposar 2 ≤ n ≤ 104.

Sortida

Per a cada cas, escriviu la suma de les distàncies infinit entre tots els
parells de punts.

Pista

La solució esperada té cost Θ(n logn) amb una constant força baixa.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vll = vector<ll>;

ll solve(vll& v) {
    sort(v.begin(), v.end());
    
    ll diff = 0;
    ll n = v.size();
    
    for (ll i = 0; i < n; ++i) {
        ll coef = i - (n - 1 - i);
        diff += v[i] * coef;
    }
    
    return diff;
}

int main() {
    int n;
    while (cin >> n) {
        vector<ll> u(n);
        vector<ll> v(n);
        
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            u[i] = x + y;
            v[i] = x - y;
        }

        ll sum_u = solve(u);
        ll sum_v = solve(v);

        cout << (sum_u + sum_v) / 2 << endl;
    }    
}