// Escriu totes les maneres de posar n reines sense amenaces en un tauler nxn.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm;
VB colu, dia1, dia2;


void escriu() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << (j == perm[i] ? 'R' : '.');
    cout << endl;
  }
  cout << string(10, '-') << endl;
}


void f(int i) {
  if (i == n) return escriu();

  for (int j = 0; j < n; ++j) {
    int d1 = i + j;
    int d2 = i - j + n - 1;
    if (not colu[j] and not dia1[d1] and not dia2[d2]) {
      colu[j] = dia1[d1] = dia2[d2] = true;
      perm[i] = j;
      f(i + 1);
      colu[j] = dia1[d1] = dia2[d2] = false;
    }
  }
}


int main() {
  cin >> n;
  perm = VI(n);
  colu = VB(n, false);
  dia1 = dia2 = VB(2*n - 1, false);
  f(0);
}
