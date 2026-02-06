// Calcula els nombres combinatoris.
// Amb memoria.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 50 + 1;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


int main() {
  VVL C(MAX, VL(MAX));
  for (int i = 0; i < MAX; ++i) C[i][0] = C[i][i] = 1;
  for (int i = 1; i < MAX; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];

  int n, x;
  while (cin >> n >> x) cout << C[n][x] << endl;
}
