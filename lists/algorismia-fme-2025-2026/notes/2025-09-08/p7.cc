// Escriu la primera combinacio en ordre lexicografic de mida n amb 0s i 1s,
// sense dos zeros seguits.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


void escriu() {
  for (int x : V) cout << x;
  cout << endl;
}


// Si existeix, escriu la primera combinacio d'n bits sense dos zeros seguits
// que comenca en V[0..i-1]. Retorna un boolea dient si l'ha trobat.
bool f(int i) {
  if (i == n) {
    escriu();
    return true;
  }

  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;
    if (f(i + 1)) return true;
  }

  V[i] = 1;
  return f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  if (not f(0)) cout << "no hi ha solucio" << endl; // amb aquest problema mai passara
}
