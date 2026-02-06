#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int MOD = 1e8 + 7;


using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;


VVI G;
VI R;


// nombre de camins que comencen a x
int f(int x) {
  int& res = R[x];
  if (res != -1) return res;
  res = 1;
  for (int y : G[x]) res = (res + f(y))%MOD;
  return res;
}


int main() {
  int m;
  while (cin >> m) {
    VS X(m), Y(m); // arestes
    map<string, int> num; // per passar els strings a ints
    for (int i = 0; i < m; ++i) {
      string s;
      cin >> X[i] >> s >> Y[i];
      if (num.find(X[i]) == num.end()) num[X[i]] = num.size();
      if (num.find(Y[i]) == num.end()) num[Y[i]] = num.size();
    }

    int n = num.size();
    G = VVI(n);
    for (int i = 0; i < m; ++i) {
      int x = num[X[i]];
      int y = num[Y[i]];
      if (X[i] > Y[i]) swap(x, y);
      G[x].push_back(y);
    }

    R = VI(n, -1);
    int res = 0;
    for (int x = 0; x < n; ++x) res = (res + f(x))%MOD;
    cout << (res - n + MOD)%MOD << endl; // restem els n camins de mida 0
  }
}
