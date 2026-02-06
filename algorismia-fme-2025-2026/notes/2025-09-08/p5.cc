// Compta totes les combinacions de mida n amb 0s i 1s,
// sense dos zeros seguits. Versio "rapida". (Son els nombres de Fibonacci.)


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


// Compta les combinacions d'n bits sense dos zeros seguits
// que comencen en V[0..i-1].
int f(int i) {
  if (i == n) return 1;

  int res = 0;
  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;
    res += f(i + 1);
  }
  V[i] = 1;
  return res + f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  cout << f(0) << endl;
}
