#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VC = vector<char>;
using VVC = vector<VC>;


int n, m;
VVC mapa;
VVL C;


// # camins des de (i, j) fins a (n - 1, m - 1)
ll f(int i, int j) {
  if (i >= n or j >= m) return 0;
  ll& res = C[i][j];
  if (res != -1) return res;
  if (mapa[i][j] == 'X') return res = 0;
  if (i == n - 1 and j == m - 1) return res = 1;
  return res = f(i + 1, j) + f(i, j + 1);
}


int main() {
  while (cin >> n >> m) {
    mapa = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (char& c : mapa[i]) cin >> c;

    C = VVL(n, VL(m, -1));
    cout << f(0, 0) << endl;
  }
}
