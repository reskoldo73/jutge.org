// P33748


#include <iostream>
#include <vector>
using namespace std;


using VS = vector<string>;
using VB = vector<bool>;


int n;
VS par;
VB triat;


void escriu() {
  cout << '{';
  bool primer = true;
  for (int i = 0; i < n; ++i)
    if (triat[i]) {
      if (primer) primer = false;
      else cout << ',';
      cout << par[i];
    }
  cout << '}' << endl;
}


void f(int i, int z, int u) {
  if (z < 0 or u < 0) return;

  if (i == n) return escriu();

  triat[i] = false;
  f(i + 1, z - 1, u);
  triat[i] = true;
  f(i + 1, z, u - 1);
}


int main() {
  int m;
  cin >> m >> n;
  par = VS(n);
  for(string& s : par) cin >> s;

  triat = VB(n);
  f(0, n - m, m);
}
