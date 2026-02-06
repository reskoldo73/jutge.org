// Escriu en ordre lexicografic totes les combinacions de mida n amb 0s i 1s.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


// Escriu les combinacions de V.size() bits que comencen en V[0..i-1].
void f(int i, VI& V) {
  int n = V.size();
  if (i == n) {
    for (int j = 0; j < n; ++j) cout << V[j];
    cout << endl;
  }
  else {
    V[i] = 0;
    f(i + 1, V);
    V[i] = 1;
    f(i + 1, V);
  }
}


int main() {
  int n;
  cin >> n;
  VI V(n);
  f(0, V);
}
