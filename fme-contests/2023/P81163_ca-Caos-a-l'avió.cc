/*
A un avió amb exactament n seients pugen n passatgers. Tothom té un bitllet amb
un número de seient assignat. Lògicament, els n nombres són diferents.

Malgrat això, el primer passatger ha perdut el bitllet i no recorda on havia de
seure, així que escull un seient uniformement a l’atzar. Cada passatger
posterior intenta triar el seu propi seient, però n’escull un dels encara
lliures uniformement a l’atzar si el seu ja està ocupat.

Quina és la probabilitat que l’últim passatger s’assegui al seu seient?

Entrada

L’entrada consisteix en diversos casos, cadascun amb un enter n. Suposeu 1 ≤ n ≤
105.

Sortida

Per a cada cas, escriviu la probabilitat demanada amb quatre decimals. Si us
cal, escriviu aquestes dues línies a l’inici del main():

    cout.setf(ios::fixed);
    cout.precision(4);
*/

#include <iostream>

using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);
    
    int n;
    while(cin >> n) {
        double ans = 1.0;
        if(n > 1) ans /= 2;
        cout << ans << endl;
    }
}