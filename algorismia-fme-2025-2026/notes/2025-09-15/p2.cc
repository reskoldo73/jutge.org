// Compta les maneres de posar n reines sense amenaces en un tauler nxn.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VB colu, dia1, dia2;


int f(int i) {
  if (i == n) return 1;

  int res = 0;
  for (int j = 0; j < n; ++j) {
    int d1 = i + j;
    int d2 = i - j + n - 1;
    if (not colu[j] and not dia1[d1] and not dia2[d2]) {
      colu[j] = dia1[d1] = dia2[d2] = true;
      res += f(i + 1);
      colu[j] = dia1[d1] = dia2[d2] = false;
    }
  }
  return res;
}


int main() {
  cin >> n;
  colu = VB(n, false);
  dia1 = dia2 = VB(2*n - 1, false);
  cout << f(0) << endl;
}
