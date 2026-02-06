// Troba un arbre generador qualsevol.


#include <iostream>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VI = vector<int>;


VI pare;


int repre(int x) {
  if (pare[x] == -1) return x;
  int r = repre(pare[x]);
  pare[x] = r;
  return r;
}


int main() {
  int n, m;
  cin >> n >> m;
  VP A(m);
  for (int i = 0; i < m; ++i) cin >> A[i].first >> A[i].second;

  pare = VI(n, -1);
  int q = n;
  for (int i = 0; q > 1 and i < m; ++i) {
     int x = A[i].first;
     int y = A[i].second;
     int rx = repre(x);
     int ry = repre(y);
     if (rx != ry) {
       pare[ry] = rx; // NO pare[y] = x
       --q;
       cout << x << ' ' << y << endl;
     }
  }
}
