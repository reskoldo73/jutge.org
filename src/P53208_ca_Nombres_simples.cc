/*
En aquest problema direm que un nombre és simple si la seva factorització no conté més de
dos factors primers diferents. Per exemple, 1, 8 = 23
, 20 = 22
⋅ 5 i 23 són nombres simples,
mentre que 126 = 2 ⋅ 32
⋅ 7 i 420 = 22
⋅ 3 ⋅ 5 ⋅ 7 no ho són.
Donats diversos naturals, podeu decidir eficientment si són simples?
Entrada
L’entrada consisteix en diverses 𝑛, totes entre 1 i 109
.
Sortida
Per a cada 𝑛, digueu si és simple o no.
Observacions
Els jocs de proves privats grossos contenen molts nombres costosos de decidir. La solució
esperada fa una mena de garbell d’Eratòstenes (diguem, d’un milió de nombres) abans de
començar a llegir l’entrada, i diverses optimitzacions.
En funció de l’eficiència de la vostra solució, el jutge us donarà una estimació (sobre 100) de
la nota màxima que podreu obtenir.
*/

//reskoldo73 (used official solution), 2026-02-12

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5; //greater than sqrt(10^9)
vector<int> prime, erat;

int fact(int n, int d) {
    while(n%d == 0) n /=d;
    return n;
}

bool simple(int n) {
    int i = 0, count = 0;
    while(n > 1) {
        if(n < maxn) {
            n = fact(n, erat[n]);
            ++count;
        }
        else {
            if(prime[i]*prime[i] >= n) return true;
            if(count == 0 and prime[i] * prime[i] * prime[i] >= n) return true;
            if(n%prime[i] == 0) {
                n = fact(n, prime[i]);
                ++count;
            }
            ++i;
        }

        if(count == 2) return n == 1;
    }
    return true;
}

int main () {
    prime = vector<int>();
    erat = vector<int>(maxn, 0);
    for(int i = 2; i < maxn; ++i) {
        if(not erat[i]) {
            prime.push_back(i);
            for(int j = i; j < maxn; j += i)
                if(not erat[j]) erat[j] = i;
        } 
    }

    int n;
    while(cin >> n) cout << (simple(n) ? "SI\n" : "NO\n");
}