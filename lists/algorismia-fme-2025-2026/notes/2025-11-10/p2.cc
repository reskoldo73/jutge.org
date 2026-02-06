// Calcula la distancia minima des d'un vertex inicial a cada vertex d'un graf.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;


void bfs(int ini) {
  VI dist(n, -1);
  queue<int> Q;
  dist[ini] = 0;
  Q.push(ini);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (dist[y] == -1) {
        dist[y] = dist[x] + 1;
        Q.push(y);
      }
  }

  for (int x = 0; x < n; ++x) cout << x << ' ' << dist[x] << endl;
}


int main() {
  int m;
  cin >> n >> m;
  G = VVI(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
  }

  int x;
  cin >> x;
  bfs(x);
}
