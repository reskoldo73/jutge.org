// Calcula els nombres de Fibonacci eficientment.
// Amb memoria.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 50 + 1;


using ll = long long;
using VL = vector<ll>;


VL F(MAX, -1);


ll f(int n) {
  if (F[n] != -1) return F[n];
  if (n <= 1) return F[n] = n;
  return F[n] = f(n - 1) + f(n - 2);
}


int main() {
  int n;
  while (cin >> n) cout << f(n) << endl;
}
