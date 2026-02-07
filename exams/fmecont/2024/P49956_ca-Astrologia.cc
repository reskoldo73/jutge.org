/*
Les notes de l’últim examen preparat pel professor Oak van ser lamentables.
Desesperat per trobar una explicació lògica al fenomen, el professor recorre a
l’astrologia. Sabent la posició relativa de tots els estels respecte de la lluna
durant la mitjanit del dia de l’examen, vol calcular quants parells d’estels
estaven aliniats amb la lluna, per si aquest nombre tingués algun significat
cabalístic.

Suposeu aquesta simplificació: La lluna i els estels són punts projectats en el
cel, el qual considerem com un pla bidimensional. La lluna ocupa l’origen, i els
estels ocupen diferents posicions (x, y), on x i y són enters. Cal calcular
quants parells (x1, y1) i (x2, y2) són tals que la recta que els uneix passa per
(0, 0).

Entrada

L’entrada consisteix en diversos casos. Cada cas comença amb el nombre d’estels
n, seguit d’n parells diferents x y amb les coordenades dels estels. Podeu
suposar 2 ≤ n ≤ 104, que les coordenades es troben entre −109 i 109, i que cap
estel es troba a l’origen.

Sortida

Per a cada cas, escriviu la quantitat de parells d’estels aliniats amb la lluna.

Pista

La solució esperada té cost inferior a Θ(n2).
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        unordered_map<double, int> m;
        int vert = 0;
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if(x != 0)  ++m[y/(double)x];
            else ++vert;
        }
        int sum = vert*(vert-1)/2;
        for(auto it : m) {
            sum += it.second * (it.second - 1) / 2;
        }
        cout << sum << endl;
    }
    

}