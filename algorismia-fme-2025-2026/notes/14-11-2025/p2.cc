// Kruskal


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using P = pair<int, int>;
using T = pair<int, P>;
using VT = vector<T>;
using VI = vector<int>;


VI pare;


int repre(int x) {
  return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}


int main() {
  int n, m;
  cin >> n >> m;
  VT A(m);
  for (int i = 0; i < m; ++i)
    cin >> A[i].second.first >> A[i].second.second >> A[i].first;

  sort(A.begin(), A.end());

  pare = VI(n, -1);
  int q = n;
  for (int i = 0; q > 1 and i < m; ++i) {
     int x = A[i].second.first;
     int y = A[i].second.second;
     int rx = repre(x);
     int ry = repre(y);
     if (rx != ry) {
       pare[ry] = rx; // NO pare[y] = x
       --q;
       cout << x << ' ' << y << ' ' << A[i].first << endl;
     }
  }
}
