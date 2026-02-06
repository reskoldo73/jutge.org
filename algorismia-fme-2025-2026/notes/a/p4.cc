#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


string s, t;
VVI D;


int min3(int a, int b, int c) {
    return min(a, min(b, c));
}


// distancia d'edicio entre s[0..i-1] i t[0..j-1]
int f(int i, int j) {
  int& res = D[i][j];
  if (res != -1) return res;
  if (i == 0) return res = j;
  if (j == 0) return res = i;
  if (s[i-1] == t[j-1]) return res = f(i - 1, j - 1);
  return res = min3(f(i - 1, j), f(i, j - 1), f(i - 1, j - 1)) + 1;
}


int main() {
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  D = VVI(n + 1, VI(m + 1, -1));
  cout << f(n, m) << endl;
}
