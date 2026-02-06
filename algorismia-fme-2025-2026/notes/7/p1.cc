// Calcula els nombres de Fibonacci ineficientment.


#include <iostream>
using namespace std;


using ll = long long;


ll f(int n) {
  if (n <= 1) return n;
  return f(n - 1) + f(n - 2);
}


int main() {
  int n;
  while (cin >> n) cout << f(n) << endl;
}
