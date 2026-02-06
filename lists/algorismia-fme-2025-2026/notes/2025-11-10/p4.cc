// Calcula un cami minim des d'un vertex inicial fins a un vertex final.


#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int n;
VVI G;


void bfs(int ini, int fi) {
  if (fi == ini) { 
    cout << ini << endl;
    return;
  }

  VI pare(n, -1);
  queue<int> Q;
  pare[ini] = -2;
  Q.push(ini);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (pare[y] == -1) {
        pare[y] = x;
        Q.push(y);

        if (y == fi) {
          stack<int> pila;
          while (y != ini) {
            pila.push(y);
            y = pare[y];
          }

          cout << ini;
          while (not pila.empty()) {
            cout << ' ' << pila.top();
            pila.pop();
          }
          cout << endl;
          return;
        }
      }
  }

  cout << "no hi ha cami entre " << x << " i " << y << endl;
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
  bfs(x, y);
}
