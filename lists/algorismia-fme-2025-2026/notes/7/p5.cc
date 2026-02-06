// Calcula els nombres combinatoris.
// Amb memoria.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 50 + 1;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


VVL C(MAX, VL(MAX, -1));


ll combi(int n, int x) {
  if (C[n][x] != -1) return C[n][x];
  if (x == 0) return C[n][x] = 1;
  if (x == n) return C[n][x] = 1;
  return C[n][x] = combi(n - 1, x) + combi(n - 1, x - 1);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << combi(n, x) << endl;
}
