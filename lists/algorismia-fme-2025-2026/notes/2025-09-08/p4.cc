// Compta totes les combinacions de mida n amb 0s i 1s,
// sense dos zeros seguits. Versio lenta.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


// Compta les combinacions d'n bits sense dos zeros seguits
// que comencen en V[0..i-1].
int f(int i) {
  if (i == n) {
    for (int j = 1; j < n; ++j)
      if (V[j-1] + V[j] == 0) return 0;
    return 1;
  }

  V[i] = 0;
  int res = f(i + 1);
  V[i] = 1;
  return res + f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  cout << f(0) << endl;
}
