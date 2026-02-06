#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int UNDEF = -1;

vector<vector<int>> g;
vector<int> p;
string a;

void print(int y) {
  vector<int> v;
  int z = y;
  while (z != 0) {
    v.push_back((g[p[z]][0] == z ? 0 : 1));
    z = p[z];
  }
  for (int k = v.size() - 1; k >= 0; --k) 
    cout << v[k];
  cout << endl;
}

void solve() {
  queue<int>  q;
  p = vector<int>(g.size(), UNDEF);
  q.push(0);
  p[0] = 0;  
  while (not q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : g[x])
      if (p[y] == UNDEF) {
	p[y] = x;
	if (a[y] == 'A') return print(y);
	q.push(y);
      }
  }
  cout << "no" << endl;
}

int main() {
  int n;
  while (cin >> n) {
    g = vector<vector<int>>(n, vector<int>(2));
    for (auto& gi : g) 
      cin >> gi[0] >> gi[1];
    cin >> a;
    solve();
  }
}
