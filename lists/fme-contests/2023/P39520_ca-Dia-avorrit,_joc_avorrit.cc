/*
L’Alice i en Bob estan avorrits, així que han decidit inventar-se un joc.
Malauradament, només tenen un tauler d’escacs infinit en les dues dimensions (x,
y ≥ 0) i una torre. Amb tants pocs elements és complicat pensar en res gaire
divertit, però han provat el següent:

En començar el joc, es col·loca la torre aleatòriament al tauler. Seguidament,
es van alternant (començant per en Bob, que s’ha cansat de ser sempre el segon),
i a cada torn el jugador a qui li toqui ha de moure la torre, fent que la seva
coordenada x o y disminueixi. Perd el primer jugador que no pot jugar.

Entrada

L’entrada consisteix en diversos casos, cadascun amb dos enters x i y, entre 0 i
1018, indicant la posició inicial de la torre.

Sortida

Escriviu qui guanyarà cada partida, suposant que ambdós jugadors juguen
perfectament.
*/

#include <iostream>

using namespace std;

using ll = long long;

int main () {
    ll x, y;
    while(cin >> x >> y) {
        cout << (x ^ y ? "Bob" : "Alice") << endl;
    }
}