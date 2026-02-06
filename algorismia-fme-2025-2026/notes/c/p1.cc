// Floyd-Warshall


#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
  int n, m;
  cin >> n >> m;
  VVI M(n, VI(n, INF));
  for (int i = 0; i < n; ++i) M[i][i] = 0;
  while (m--) {
    int i, j, c;
    cin >> i >> j >> c;
    M[i][j] = c;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << ' ' << (M[i][j] == INF ? -1 :M[i][j]);
    cout << endl;
  }
}
