// Tots els canvis.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


const VI moneda = { 50, 20, 10, 5, 2, 1 };


VI V(6);


void escriu() {
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < V[i]; ++j) cout << ' ' << moneda[i]; // PE
  cout << endl;
}


void f(int i, int n) {
  if (i == 5) {
    V[5] = n;
    return escriu();
  }

  for (int j = n/moneda[i]; j >= 0; --j) {
    V[i] = j;
    f(i + 1, n - j*moneda[i]);
  }
}


int main() {
  int n;
  while (cin >> n) {
    f(0, n);
    cout << endl;
  }
}
