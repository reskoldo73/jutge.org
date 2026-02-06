#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI V, L;


// longitud de la LIS de V[0..n-1]
int lis(int n) {
  int& res = L[n];
  if (res != -1) return res;
  res = 1;
  for (int i = 1; i < n; ++i)
    if (V[i-1] < V[n-1]) res = max(res, lis(i) + 1);
  return res;
}


int main() {
  int n;
  while (cin >> n) {
    V = VI(n);
    for (int& x : V) cin >> x;

    L = VI(n + 1, -1);
    int res = 0;
    for (int i = 1; i <= n; ++i) res = max(res, lis(i));
    cout << res << endl;
  }
}
