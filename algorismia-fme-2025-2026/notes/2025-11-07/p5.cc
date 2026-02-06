// Compta el nombre de components connexs.


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
  int q = 0;
  for (int x = 0; x < n; ++x)
    if (not vist[x]) {
      ++q;
      dfs(x);
    }
  cout << "nombre de components connexs: " << q << endl;
}
