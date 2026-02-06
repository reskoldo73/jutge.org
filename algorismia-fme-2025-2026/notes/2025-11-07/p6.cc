// Diu si el graf es un bosc.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI vist;


void dfs(int x, int& v, int& a) {
  if (vist[x]) return;
  vist[x] = true;
  ++v;
  for (int y : G[x]) {
    ++a;
    dfs(y, v, a);
  }
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
  bool bosc = true;
  for (int x = 0; bosc and x < n; ++x)
    if (not vist[x]) {
      int v = 0;
      int a = 0;
      dfs(x, v, a);
      if (a/2 != v - 1) bosc = false;
    }
  cout << (bosc ? "bosc" : "no bosc") << endl;
}
