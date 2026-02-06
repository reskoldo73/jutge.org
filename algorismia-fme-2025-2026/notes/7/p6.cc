// Calcula els nombres combinatoris.
// Amb memoria, versio alternativa.


#include <iostream>
#include <vector>
using namespace std;


const int MAX = 50 + 1;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;


VVL C(MAX, VL(MAX, -1));


ll combi(int n, int x) {
  if (x < 0 or x > n) return 0;
  ll& res = C[n][x];
  if (res != -1) return res;
  if (n == 0) return res = 1;
  return res = combi(n - 1, x) + combi(n - 1, x - 1);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << combi(n, x) << endl;
}
