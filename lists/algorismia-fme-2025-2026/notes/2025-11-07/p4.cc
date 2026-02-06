// Diu si el graf es connex.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI vist;


void dfs(int x) {
  if (vist[x]) return;
  vist[x] = true;
  for (int y : G[x]) dfs(y);
}


int main() {
  int n, m;
  cin >> n >> m;
  G = VVI(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vist = VI(n, false);
  dfs(0);
  bool ok = true;
  for (int x = 0; ok and x < n; ++x)
    if (not vist[x]) ok = false;
  cout << (ok ? "connex" : "no connex") << endl;
}
