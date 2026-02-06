#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;


const int MOD = 1e8 + 7;


int n, m;
VVC M;
VVVI R;


// # maneres de guanyar des de (i, j) amb k unitats d'energia
int f(int i, int j, int k) {
  if (j < 0 or j >= m or k < 0) return 0;
  int& res = R[i][j][k];
  if (res != -1) return res;
  if (M[i][j] == 'X') return res = 0;
  if (i == n - 1) return res = (k == 0);
  if (isdigit(M[i][j])) k -= M[i][j] - '0';
  return res = (f(i + 1, j, k) + f(i, j - 1, k - 1) + f(i, j + 1, k - 1))%MOD;
}


int main() {
  int e;
  while (cin >> n >> m >> e) {
    M = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (char& c : M[i]) cin >> c;

    R = VVVI(n, VVI(m, VI(e + 1, -1)));
    int res = 0;
    for (int j = 0; j < m; ++j) res = (res + f(0, j, e))%MOD;
    cout << res << endl;
  }
}
