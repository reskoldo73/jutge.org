/*
Aquí tractem amb expressions regulars simplificades, les quals codifiquen paraules. En el
que segueix, sigui 𝑃 una paraula no buida formada només amb lletres minúscules, sigui 𝐷
un dígit entre 1 i 9, i sigui 𝑆 = 𝐸1
, … , 𝐸𝑛 una seqüència no buida d’expressions regulars. Una
expressió regular pot ser:
• 𝐷[𝑃] : codifica 𝐷 còpies de 𝑃.
• 𝐷[𝑆] : codifica 𝐷 còpies de la concatenació de les codificacions de 𝐸1
, …, 𝐸𝑛
.
Diversos exemples:
• 1[hola] codifica hola.
• 3[hi] codifica hihihi.
• 1[1[hola]3[hi]] codifica holahihihi.
• 2[1[hola]3[hi]] codifica holahihihiholahihihi.
Com podeu veure als exemples d’entrada, aquesta definició recursiva permet que hi hagi
tants nivells com es vulgui de [ ... ].
Entrada
L’entrada consisteix en diverses expressions regulars.
Sortida
Escriviu la paraula codificada per cada expressió regular donada.
Observació
Si 𝑠 i 𝑡 són strings, i 𝑐 és un caràcter, aquestes operacions són vàlides:
s += t; // afegeix una copia de t a la dreta d's
s += c; // afegeix una copia de c a la dreta d's
Pista
La solució esperada és recursiva. El main() només conté:
char c;
while (cin >> c) cout << expressio(c) << endl;
*/

//reskoldo73, 2026-02-12

#include <iostream>

using namespace std;

int isint(char c) {
    if('0' <= c and c <= '9') return int(c - '0');
    return -1;
}

string expressio(char c) {
    string ans = "";
    int cint = isint(c);

    if(cint > -1) {
        char temp;
        cin >> temp; //'['
        string aux = expressio(temp);
        for(int i = 0; i < cint; ++i) ans += aux;
    }
    else { //c == '['
        while(c != ']') {
            cint = isint(c);
            if(cint > -1) {
                ans += expressio(c);
                cin >> c;
            }
            else {
                if(c != '[') ans += c;
                cin >>c;
            }
        }
    }           

    return ans;
}

int main () {
    char c;
    while(cin >> c) cout << expressio(c) << endl;
}