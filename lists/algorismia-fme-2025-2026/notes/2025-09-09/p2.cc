// P45965


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


void escriu() {
  for (int i = 0; i < n; ++i)
    cout << (i ? " " : "") << V[i];
  cout << endl;
}


void f(int i, int z, int u) {
  if (z < 0 or u < 0) return;

  if (i == n) return escriu();

  V[i] = 0;
  f(i + 1, z - 1, u);
  V[i] = 1;
  f(i + 1, z, u - 1);
}


int main() {
  int u;
  cin >> n >> u;
  V = VI(n);
  f(0, n - u, u);
}
