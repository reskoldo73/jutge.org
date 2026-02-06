/*
El passat 1 de desembre es va celebrar el SWERC 2024, on van participar tres
equips de la UPC (amb tots nou integrants, matemàtics). Evidentment, als equips
els agradaria saber com quedaran abans de la competició. Per això, en Jan
(UPC-3) i en Bernat (UPC-1) van decidir jugar al joc anomenat “Bottle of truth”.
Aquest joc consisteix a deixar anar un “factou” (una proposició) i fer girar
l’ampolla com als “bottle flip challenges” del 2014. Si l’ampolla queda dempeus,
el factou és cert. Si no, el factou és fals.

Es va jugar tres cops al Bottle of Truth: El primer cop, en Bernat va dir:
“UPC-1 resoldrà més problemes que UPC-2”. L’ampolla va caure dempeus.
Immediatament després, en Jan va dir: “UPC-3 resoldrà més problemes que UPC-2”.
Tràgicament, l’ampolla va caure a terra. Ara bé, en Bernat, en un intent
desesperat de salvar la “performance” d’en Jan al Swerc, va dir: “UPC-2 resoldrà
més problemes que UPC-3”. I l’ampolla va tornar a caure a terra.

Entrada

L’entrada consisteix en diversos casos, cadascun amb tres enters: el nombre de
problemes resolts per UPC-1, UPC-2 i UPC-3, respectivament. Podeu suposar que
tots els nombres estan entre 0 i 106.

Sortida

Per a cada cas, escriviu “factou” si l’ampolla va deixar anar tres factous, o bé
“infactou” si l’ampolla va dir alguna tonteria.
*/

#include <iostream>

using namespace std;

int main () {
    int a, b, c;
    while(cin >> a >> b >> c) cout << (a > b and c == b ? "factou" : "infactou") << endl;
}