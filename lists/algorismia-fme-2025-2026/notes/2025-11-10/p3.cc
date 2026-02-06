// Calcula la distancia minima des d'un vertex inicial a un vertex final.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int INF = 1e9;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;


int bfs(int ini, int fi) {
  if (ini == fi) return 0;

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
        if (y == fi) return dist[y];
      }
  }

  return INF;
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

  int x, y;
  cin >> x >> y;
  cout << "distancia minima entre " << x << " i " << y << ": " << bfs(x, y) << endl;
}
