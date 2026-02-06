// Compta els vertexs del component connex del vertex x.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI vist;


int dfs(int x) {
  if (vist[x]) return 0;
  vist[x] = true;
  int res = 1;
  for (int y : G[x]) res += dfs(y);
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
    G[y].push_back(x);
  }

  int x;
  cin >> x;
  vist = VI(n, false);
  cout << dfs(x) << endl;
}
