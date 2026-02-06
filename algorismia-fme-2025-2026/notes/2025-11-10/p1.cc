// Escriu els vertexs d'un graf en ordre de distancia a un vertex inicial.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;


void bfs(int ini) {
  VI vist(n, false);
  queue<int> Q;
  vist[ini] = true;
  Q.push(ini);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    cout << x << endl;
    for (int y : G[x])
      if (not vist[y]) {
        vist[y] = true;
        Q.push(y);
      }
  }
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
