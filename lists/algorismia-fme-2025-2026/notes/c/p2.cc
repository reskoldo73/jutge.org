// Donat un DAG, troba la longitud del cami mes llarg que conte.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI R;


// longitud del cami mes llarg que surt d'x
int f(int x) {
  int& res = R[x];
  if (res != -1) return res;
  res = 0;
  for (int y : G[x]) res = max(res, 1 + f(y));
  return res;
}


int main() {
  int n, m;
  cin >> n >> m;
  G = VVI(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
  }

  R = VI(n, -1);
  int res = 0;
  for (int x = 0; x < n; ++x) res = max(res, f(x));
  cout << res << endl;
}
