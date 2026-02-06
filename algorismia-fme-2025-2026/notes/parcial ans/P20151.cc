#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> t;
vector<vector<int>> u;
vector<bool> c;

void gen(int i, int j, bool r) {
  
  if (i == n) {

    for (int j = 0; j < n; ++j)
      if (c[j]) return;
    
    for (const auto& ti : t)
      cout << ti << endl;
    cout << endl;
    return;
  }

  if (j == n) {
    if (not r) gen(i+1, 0, false);
    return;
  }

  if (u[i][j] == 0 and c[j]) 
    return;
  
  if (t[i][j] == '.') {
    gen(i, j+1, r);
    return;
  }

  if (t[i][j] == 'X') {
    gen(i, j+1, not r);
    return;
  }
  
  t[i][j] = '.';
  gen(i, j+1, r);

  c[j] = not c[j];
  t[i][j] = 'X';
  gen(i, j+1, not r);
  c[j] = not c[j];
  t[i][j] = '?';
}

int main() {
  while (cin >> n) {
    t = vector<string>(n);
    u = vector<vector<int>>(n, vector<int>(n));
    c = vector<bool>(n, false);
    for (auto& ti : t) cin >> ti;
    for (int i = n-1; i >= 0; --i)
      for (int j = 0; j < n; ++j) {
	if (t[i][j] == '?') {
	  u[i][j] = (i < n-1 ? u[i+1][j] : 0) + 1;
	}
	else {
	  u[i][j] = (i < n-1 ? u[i+1][j] : 0);
	  c[j] = c[j] xor (t[i][j] == 'X');
	}
      }
    gen(0, 0, false);
    cout << string(10, '-') << endl;
  }
}
