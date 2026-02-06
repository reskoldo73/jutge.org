// Bellman-Ford, versio 1.
// Suposa que no hi ha cicles negatius, i sempre fa n - 1 passos.
// Totes les versions comencen al vertex 0,
// i suposen que tot el graf es accessible des del vertex 0.


#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e9;


using VI = vector<int>;


int n, m;
VI X, Y, C;
VI d;


void bellman_ford() {
  d = VI(n, INF);
  d[0] = 0;
  for (int pas = 1; pas <= n - 1; ++pas) {
    cout << "pas " << pas << endl;
    for (int i = 0; i < m; ++i) {
      int d2 = d[X[i]] + C[i];
      if (d2 < d[Y[i]]) {
        d[Y[i]] = d2;
        cout << "nova distancia per a " << Y[i] << " : " << d2 << endl;
      }
    }
    cout << string(10, '-') << endl;
  }
}


int main() {
  cin >> n >> m;
  X = Y = C = VI(m);
  for (int i = 0; i < m; ++i) cin >> X[i] >> Y[i] >> C[i];

  bellman_ford();

  for (int x = 0; x < n; ++x) cout << "millor distancia des de 0 fins a " << x << " : " << d[x] << endl;
}
