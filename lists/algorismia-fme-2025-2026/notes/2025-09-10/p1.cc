// Donada una n, escriu les n! permutacions de {1, ..., n}.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm; // permutacio que creem
VB usat; // recorda els nombres que s'han usat



void escriu() {
//  for (int i = 0; i < n; ++i) cout << (i ? " " : "") << perm[i];
//  cout << endl;

  cout << '(';
  for (int i = 0; i < n; ++i) cout << (i ? "," : "") << perm[i] + 1;
  cout << ')' << endl;
}


// Escriu totes les permutacions de 1..n que comencen amb perm[0..i-1].
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
