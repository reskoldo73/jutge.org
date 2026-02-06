// Escriu totes les maneres de posar n torres sense amenaces en un tauler nxn.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm;
VB usat;


void escriu() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      cout << (j == perm[i] ? 'T' : '.');
    cout << endl;
  }
  cout << string(10, '-') << endl;
}


void f(int i) {
  if (i == n) return escriu();

  for (int x = 0; x < n; ++x)
    if (not usat[x] ) {
      usat[x] = true;
      perm[i] = x;
      f(i + 1);
      usat[x] = false;
    }
}


int main() {
  cin >> n;
  perm = VI(n);
  usat = VB(n, false);
  f(0);
}
