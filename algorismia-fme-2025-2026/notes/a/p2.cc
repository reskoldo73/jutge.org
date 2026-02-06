#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VI = vector<int>;


VI moneda;
VVL C;


// # maneres de sumar x amb les i primeres monedes, podent repetir
ll f(int x, int i) {
  if (x < 0) return 0;
  ll& res = C[x][i];
  if (res != -1) return res;
  if (i == 0) return res = (x == 0);
  return res = f(x, i - 1) + f(x - moneda[i-1], i);
}


int main() {
  int suma, n;
  cin >> suma >> n;
  moneda = VI(n);
  for (int& x : moneda) cin >> x;

  C = VVL(suma + 1, VL(n + 1, -1));
  cout << f(suma, n) << endl;
}
