// Algoritmo de la tortuga y la liebre (Floyd) para detectar ciclos sin necesidad de almacenar la secuencia
// https://jutge.org/problems/P69781_en
#include <iostream>
using namespace std;

const int infinity = 1e8 + 1;
int x, y;

int f(int n) {
    return (n & 1) ? (3 * n + y) : (n / 2 + x);
}

int main() {
    int n;
    while (cin >> x >> y >> n) {
        int tortoise = f(n), hare = f(tortoise);

        // Si l es la longitud del ciclo, cuando i >= (posición en la que empieza) y además i sea múltiplo de l, tendremos x_{i} = x_{2i}
        while (tortoise != hare && tortoise < infinity) {
            tortoise = f(tortoise);
            if (hare < infinity) hare = f(hare);
            if (hare < infinity) hare = f(hare);
        }
        if (tortoise >= infinity) cout << tortoise << "\n";
        else {
            // Ahora las dos posiciones se diferencian en un múltiplo de la longitud del ciclo. Busca su longitud exacta
            int cycle = 1;
            hare = f(tortoise);
            while (tortoise != hare) {
                hare = f(hare);
                ++cycle;
            }
            cout << cycle << "\n";
        }
    }
    return 0;
}

