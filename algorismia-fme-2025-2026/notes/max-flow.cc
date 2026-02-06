#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int INF = 1e9;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;
VVI M;


int flow() {
  queue<int> Q;
  VI flux(n);
  VI pare(n, -1);
  Q.push(0);
  flux[0] = INF;
  pare[0] = -2;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (pare[y] == -1 and M[x][y]) {
        Q.push(y);
        flux[y] = min(flux[x], M[x][y]);
        pare[y] = x;

        if (y == n - 1) {
          int f = flux[y];
          while (y != 0) {
            int p = pare[y];
            M[p][y] -= f;
            M[y][p] += f;
            y = p;
          }
          return f;
        }
      }
  }
  return 0;
}


int main() {
  int m;
  cin >> n >> m;
  G = VVI(n);
  M = VVI(n, VI(n, 0));
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(y);
    G[y].push_back(x);
    M[x][y] = c; // graf dirigit
  }

  int res = 0;
  int f;
  while ((f = flow())) res += f;
  cout << res << endl;
}
