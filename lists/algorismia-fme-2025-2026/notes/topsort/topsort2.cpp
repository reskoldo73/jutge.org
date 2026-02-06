// Ordenacio topologica d'un DAG G (alternativa, amb DFS).
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

void dfs(int v, const VVI& G, vector<bool>& visited, vector<int>& order) {
    visited[v] = true;
    for (int w : G[v])
        if (!visited[w])
            dfs(w, G, visited, order);
    order.push_back(v);
}

int main() {
  int n, m;
  cin >> n >> m;
  VVI G(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
  }

  vector<bool> visited(n);
  vector<int> order;
  for (int v = 0; v < n; ++v)
    if (!visited[v]) 
        dfs(v, G, visited, order);

  for (auto it = order.rbegin(); it != order.rend(); ++it) cout << *it << endl;
}
