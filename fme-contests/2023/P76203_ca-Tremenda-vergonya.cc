/*
Per celebrar la desena classificació per a les finals mundials, els equips de
programació de la UPC van decidir organitzar una performance sorpresa al Roura
(el seu entrenador) enmig d’un examen final d’Algorísmia.

Aquesta actuació va ser molt improvisada, i la majoria de les parts van fer
passar vergonya a tothom. Després d’una anàlisi exhaustiva, els organitzadors
van aconseguir descriure cada part i amb dos paràmetres: la quantitat intrínseca
de cringe ci, i la vergonya vi que va passar el Roura durant aquella part. Es
volen penjar parts de la performance al YouTube per tal de maximitzar la
vergonya del Roura, però sense que el cringe total passi d’un cert límit C.
Sabríeu fer-ho?

Entrada

L’entrada consisteix en diversos casos, només amb nombres enters, amb el nombre
de parts ‍n i C (ambdós entre 1 i 1000), seguits dels n parells ci vi, tots
entre 1 i 109.

Sortida

Per a cada cas, escriviu la màxima suma possible de les vi, però amb la condició
que la suma de les ci corresponents no passi de C.
*/

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi memo;

int dp(int i, int j) {

}

int main () {
    int n;
    while(cin >> n) {
        int k;
        cin >> k;

    }
}






#include <iostream>
#include <vector>
#include <algorithm> // Needed for max()

using namespace std;

using ll = long long; 
// We need long long for the memo table because the sum of 'v' can exceed 2^31
using vll = vector<ll>;
using vvll = vector<vll>;

int n; // Number of items
int C; // Max cringe capacity
vector<int> c_vals; // The "weights"
vector<int> v_vals; // The "values"
vvll memo;

// i = current item index we are considering
// j = remaining cringe capacity we have left
ll dp(int i, int j) {
    // Base Case: If we have gone through all items (index n)
    if (i == n) return 0;
    
    // Check if we already calculated this state
    if (memo[i][j] != -1) return memo[i][j];
    
    // OPTION 1: Skip this item
    // We move to item i+1, keeping the same capacity j
    ll skip = dp(i + 1, j);
    
    // OPTION 2: Take this item (only if it fits in the remaining capacity)
    ll take = -1;
    if (c_vals[i] <= j) {
        // We add the value v[i], and move to item i+1 with reduced capacity
        take = v_vals[i] + dp(i + 1, j - c_vals[i]);
    }
    
    // Store the best result in memo and return it
    return memo[i][j] = max(skip, take);
}

int main () {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n) {
        cin >> C; 

        // Resize vectors to fit the current test case
        c_vals.resize(n);
        v_vals.resize(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> c_vals[i] >> v_vals[i];
        }

        // Initialize memo table with -1
        // Size: n items (rows) x (C + 1) capacity (columns)
        memo.assign(n, vll(C + 1, -1));

        // Start DP from the 0th item with full capacity C
        cout << dp(0, C) << endl;
    }
}