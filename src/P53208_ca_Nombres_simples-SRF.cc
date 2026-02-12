// solucio que obte un score al jutge de 100/100
#include <iostream>
#include <vector>
using namespace std;
// n'hi hauria prou fins a l'arrel de 10^9,
// pero no fa mal arribar una mica mes lluny
const int M = 1e6 + 1;
using VI = vector<int>;
// "esborra" el factor f d'n
void treu(int f, int& n) {
while (n%f == 0) n /= f;
}
bool es_simple(int n, const VI& primer, const VI& factor) {
int q = 0; // nombre de factors trobats
int i = 0; // posicio dins del vector primer
while (n > 1) { // tambe, sempre es complira q <= 1
if (n < M) {
treu(factor[n], n);
++q;
}
else {
// comprova si el que queda d'n es primer:
if (primer[i]*primer[i] >= n) return true;
// quan q es 0,
// comprova si el que queda d'n no pot tenir mes de 2 factors:
if (q == 0 and primer[i] * primer[i] * primer[i] >= n)
return true;
if (n%primer[i] == 0) {
treu(primer[i], n);
++q;
}
++i;
}
// quan q es 2, ja sabem la resposta:
if (q == 2) return n == 1;
}
return true;
}
int main() {
VI factor(M, 0); // factor primer mes petit de cada nombre fins a M-1
VI primer;
// tots els primers fins a M-1
for (int i = 2; i < M; ++i) { // garbell d'Eratostenes
if (factor[i] == 0) {
primer.push_back(i);
for (int j = i; j < M; j += i) {
if (factor[j] == 0) factor[j] = i;
}
}
}
int n;
while (cin >> n) {
if (es_simple(n, primer, factor)) cout << "SI" << endl;
else cout << "NO" << endl;
}
}