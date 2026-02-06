// Prefix sum.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int main() {
  int n;
  cin >> n;
  VI V(n);
  for (int& x : V) cin >> x;

  // pre[i] = suma de V[0..i] 
  VI pre(n);
  for (int i = 0; i < n; ++i) pre[i] = (i ? pre[i-1] : 0) + V[i];

  int e, d; // cal calcular V[e] + ... + V[d]
  while (cin >> e >> d) cout << pre[d] - (e ? pre[e-1] : 0) << endl;
}
