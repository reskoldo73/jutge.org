/*
Un rètol dels antics, amb bombetes que estan enceses o apagades, es pot
codificar amb 5 × 3 bits, de dalt a baix, i cada fila d’esquerra a dreta. A la
dreta podeu veure les posicions de les bombetes.
Donat un rètol amb 𝑛 símbols, cadascun codificat amb 15 bits, escriviu-lo.
0 1 2
3 4 5
6 7 8
9 10 11
12 13 14
Entrada
L’entrada consisteix en diversos rètols, cadascun descrit amb un natural 𝑛 ≥ 1, seguit de les
codificacions dels 𝑛 símbols del rètol. Cada codificació és una paraula amb 15 caràcters que
són tots ‘0’ o ‘1’.
Sortida
Escriviu cada rètol seguint el format dels exemples. Cal usar espais per a les bombetes apagades, 
lletres O majúscula per a les enceses, i cal separar els símbols sentre si i amb els costats
amb dues columnes d’espais. Rodejeu el rètol amb guions a dalt i a baix, amb barres verticals
als costats, i poseu quatre asteriscs a les cantonades.
*/

//reskoldo73, 2026-02-12

#include <iostream>
#include <vector>

using namespace std;

void border(int n) {
    cout << '*';
    for(int i = 0; i < 5*n+2; ++i) cout << '-';
    cout << '*' << endl;    
}

int main () {
    int n;
    while(cin >> n) {
        vector<string> inp(n);
        for(int i = 0; i < n; ++i) cin >> inp[i];

        border(n);
        for(int i = 0; i < 5; ++i) {
            cout << '|';

            for(int j = 0; j < n; ++j) {
                cout << "  ";
                for(int k = 0; k < 3; ++k) cout << (inp[j][3*i+k]=='0' ? ' ' : 'O');
            }

            cout << "  |\n";
        }

        border(n);

    }
}
