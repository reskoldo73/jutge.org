// Diu si el graf es un bosc.


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
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  vist = VI(n, false);
  int q = 0;
  for (int x = 0; x < n; ++x)
    if (not vist[x]) {
      ++q;
      dfs(x);
    }
  cout << (n == m + q ? "bosc" : "no bosc") << endl;
}
