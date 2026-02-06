#include <iostream>
#include <vector>
using namespace std;


const int MAX = 30 + 1;


using ll = long long;
using VL = vector<ll>;


VL P(MAX, -1);


// # parentitzacions correctes amb n parentesis de cada
ll par(int n) {
  ll& res = P[n];
  if (res != -1) return res;
  if (n == 0) return res = 1;
  res = 0;
  for (int i = 0; i < n; ++i) res += par(i)*par(n - 1 - i);
  return res;
}


int main() {
  int n;
  while (cin >> n) cout << par(n) << endl;
}
