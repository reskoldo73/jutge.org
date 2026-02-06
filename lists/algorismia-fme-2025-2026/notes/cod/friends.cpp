// https://jutge.org/problems/P22662_en
#include <algorithm>
#include <iostream>
#include <vector>
using std::vector, std::cin, std::cout, std::max_element;     // para evitar colisión de nombres con std::rank, std::size

const int maxn = 100000;
vector<int> sieve(maxn + 1);

// Devuelve los factores primos de n (sin multiplicidad), asumiendo sieve[] ha sido rellenada
vector<int> prime_factors(int n) {
    vector<int> ret;
    while (n > 1) {
        int p = sieve[n] > 0 ? sieve[n] : n;
        ret.push_back(p);
        while (n % p == 0) n /= p;
    }
    return ret;
}

// Estructura de datos union-find
vector<int> parent, rank, size;

int find(int v) {
    if (parent[v] == -1) return v;
    else return parent[v] = find(parent[v]);
}

void merge(int a, int b) {
    if (a != b) {
        if (rank[a] < rank[b]) {
            parent[a] = b; 
            size[b] += size[a]; 
        } else {
            parent[b] = a;
            if (rank[a] == rank[b]) ++rank[a];
            size[a] += size[b];
        }
    }
}

int main() {
    // Calcula sieve[n] = factor primo más pequeño de n (o 0 si es primo) para n > 1
    for (int n = 2; n * n <= maxn; ++n)
        if (!sieve[n])
            for (int m = n * n; m <= maxn; m += n)
                if (!sieve[m])
                    sieve[m] = n;
    int n;
    while (cin >> n) {
        // Inicializa union-find. En realidad solo necesitaría los primos que dividan algún número de la entrada, pero por simplicidad considero todos los números hasta maxn
        rank.assign(maxn + 1, 0);
        parent.assign(maxn + 1, -1);
        size.assign(maxn + 1, 0);
        // Procesa los números y mezcla todos los primos que dividan al mismo número
        for (int i = 0; i < n; ++i) {
            int vi; 
            cin >> vi;
            int first_prime = -1;
            for (int p : prime_factors(vi)) {
                if (first_prime < 0) {
                    first_prime = p;
                    ++size[find(p)];
                } else 
                    merge(find(first_prime), find(p));
            }
        }
        cout << *max_element(size.begin(), size.end()) << "\n";
    }
    return 0;
}
