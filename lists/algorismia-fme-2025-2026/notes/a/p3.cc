#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


string s, t;
VVI C;


// longitud de la subsequencia comuna mes llarga entre s[0..i-1] i t[0..j-1]
int f(int i, int j) {
  int& res = C[i][j];
  if (res != -1) return res;
  if (i == 0 or j == 0) return res = 0;
  if (s[i-1] == t[j-1]) return res = f(i - 1, j - 1) + 1;
  return res = max(f(i - 1, j), f(i, j - 1));
}


int main() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  C = VVI(n + 1, VI(m + 1, -1));
  cout << f(n, m) << endl;
}
