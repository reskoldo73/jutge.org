#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> valor('Z' - 'A' + 1);
  valor[0] = 1;
  for (int k = 1; k < int(valor.size()); ++k) {
    valor[k] = valor[k-1] + k + 1;
  }

  vector<string> q;
  string linia;
  while (cin >> linia) {
    q.push_back(linia);
  }

  int n = q.size();
  int m = q[0].size();

  vector<vector<int>> s(n+1, vector<int>(m+1, 0));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      s[i][j] = s[i][j-1] + s[i-1][j] + valor[ q[i-1][j-1] - 'A' ] - s[i-1][j-1];
    }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j > 1) cout << " ";
      cout << s[i][j];
    }
    cout << endl;
  }
}
