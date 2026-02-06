// Bellman-Ford, versio 3.
// Comprova que no hi hagi cicles negatius, i s'atura si no hi ha canvis.


#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e9;


using VI = vector<int>;


int n, m;
VI X, Y, C;
VI d;


// retorna true si no hi ha cicles negatius
bool bellman_ford() {
  d = VI(n, INF);
  d[0] = 0;
  bool canvi = true;
  for (int pas = 1; canvi and pas <= n - 1; ++pas) {
    canvi = false;
    cout << "pas " << pas << endl;
    for (int i = 0; i < m; ++i) {
      int d2 = d[X[i]] + C[i];
      if (d2 < d[Y[i]]) {
        canvi = true;
        d[Y[i]] = d2;
        cout << "nova distancia per a " << Y[i] << " : " << d2 << endl;
      }
    }
    cout << string(10, '-') << endl;
  }

  if (not canvi) return true;

  for (int i = 0; i < m; ++i)
    if (d[X[i]] + C[i] < d[Y[i]]) return false;
  return true;
}


int main() {
  cin >> n >> m;
  X = Y = C = VI(m);
  for (int i = 0; i < m; ++i) cin >> X[i] >> Y[i] >> C[i];

  if (not bellman_ford()) cout << "algun cicle negatiu!!!" << endl;
  else
    for (int x = 0; x < n; ++x) cout << "millor distancia des de 0 fins a " << x << " : " << d[x] << endl;
}
