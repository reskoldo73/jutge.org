/*
El professor Oak està redactant part d’una notícia sobre 9 ‍estudiants que,
agrupats en tres equips de tres, han participat no-se-sap-on. Escrivint els
integrants d’un dels equips, ordenats per cognom, se n’adona que casualment
tenen cognoms alfabèticament alts. De fet, si ordenem els 9 cognoms del més
petit (1) al més gran (9), aquest equip té els números 5, 8 i 9. La suma és 5 +
8 + 9 = 22, que és a prop de la màxima suma possible: 7 + 8 + 9 = 24.


Sorprés que la suma sigui tan alta, en calcula la probabilitat. Específicament,
quina és la probabilitat que la suma sigui almenys s, suposant que cadascun dels
9 estudiants tingui la mateixa probabilitat de pertànyer a l’equip?

Entrada

L’entrada consisteix en diversos casos, cadascun amb una s entre 6 i 24.

Sortida

Per a cada s, escriviu amb quatre decimals la probabilitat que la suma dels
números dels tres integrants sigui almenys s. Escriviu aquestes dues línies a
l’inici del main():

    cout.setf(ios::fixed);
    cout.precision(4);
*/

#include <iostream>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int s;
    const double total = 84.0;

    while (cin >> s) {
        int count = 0;
        
        for (int i = 1; i <= 9; ++i) 
            for (int j = i + 1; j <= 9; ++j) 
                for (int k = j + 1; k <= 9; ++k) 
                    if (i + j + k >= s) 
                        ++count;
                    
        cout << count / total << endl;
    }
}