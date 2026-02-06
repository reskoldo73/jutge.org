/*
L’Edgar i en Fèlix juguen al joc següent: Tenen una bossa amb n pedres i, a cada
torn, en poden agafar entre 1 i m. Guanya qui s’emporti l’última pedra.

Per exemple, si n = 4, m = 2 i comença l’Edgar, pot escollir entre agafar una o
dues pedres. Si n’agafés dues, en Fèlix agafaria les altres dues i guanyaria.
Per tant, a l’Edgar li convé agafar-ne una, deixant-ne tres al Fèlix. Es pot
demostrar que en Fèlix perdrà faci el que faci, si l’Edgar continua la partida
de manera òptima.

Heu d’esbrinar qui guanyarà el joc, suposant que es juga de forma òptima i que
l’Edgar és qui comença.

Entrada

L’entrada consisteix en diversos casos, cadascun amb els dos enters n i m. Podeu
suposar 1 ≤ m ≤ n ≤ 109.

Sortida

Per a cada cas, escriviu el nom del guanyador.
*/

#include <iostream>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) cout << (n % (m+1) ? "Edgar" : "Felix") << endl;
}