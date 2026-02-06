#include <iostream>
#include <vector>
using namespace std;


const int MAX = 70 + 1;


using ll = long long;
using VL = vector<ll>;


VL Z(MAX, -1);
VL U(MAX, -1);


ll un(int n);


// # sequencies d'n bits sense dos 0s seguits, acabades en 0
ll zero(int n) {
  ll& res = Z[n];
  if (res != -1) return res;
  if (n == 1) return res = 1;
  return res = un(n - 1);
}


// # sequencies d'n bits sense dos 0s seguits, acabades en 1
ll un(int n) {
  ll& res = U[n];
  if (res != -1) return res;
  if (n == 1) return res = 1;
  return res = zero(n - 1) + un(n - 1);
}


int main() {
  int n; // n >= 1
  while (cin >> n) cout << zero(n) + un(n) << endl;
}
