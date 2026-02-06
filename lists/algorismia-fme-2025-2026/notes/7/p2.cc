// Calcula els nombres de Fibonacci eficientment.
// Ho precalcula tot al main.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 50 + 1;


using ll = long long;
using VL = vector<ll>;


int main() {
  VL F(MAX);
  F[0] = 0;
  F[1] = 1;
  for (int n = 2; n < MAX; ++n) F[n] = F[n-1] + F[n-2];

  int n;
  while (cin >> n) cout << F[n] << endl;
}
