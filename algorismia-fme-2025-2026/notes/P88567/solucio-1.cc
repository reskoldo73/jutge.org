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

  vector<vector<int>> s(n, vector<int>(m));
  s[0][0] = valor[ q[0][0] - 'A' ];
  for (int i = 1; i < n; ++i) s[i][0] = s[i-1][0] + valor[ q[i][0] - 'A' ];
  for (int j = 1; j < m; ++j) s[0][j] = s[0][j-1] + valor[ q[0][j] - 'A' ];
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < m; ++j) {
      s[i][j] = s[i][j-1] + s[i-1][j] + valor[ q[i][j] - 'A' ] - s[i-1][j-1];
    }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j > 0) cout << " ";
      cout << s[i][j];
    }
    cout << endl;
  }
}
