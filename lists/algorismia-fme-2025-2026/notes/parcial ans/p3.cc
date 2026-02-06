#include <iostream>
#include <vector>
using namespace std;


const int MAX = 1e7 + 1;


using VI = vector<int>;


VI primer(MAX, true);
VI V, R;


// maxim a V[0..i]
int f(int i) {
  if (i < 0) return 0;
  int& res = R[i];
  if (res != -1) return res;
  res = 0;
  int suma = 0;
  for (int j = i; j >= 0; --j) {
    suma += V[j];
    res = max(res, (primer[suma] ? suma : 0) + f(j - 1));
  }
  return res;
}


int main() {
  // Eratostenes (no cal cap optimitzacio)
  primer[0] = primer[1] = false;
  for (int i = 2; i < MAX; ++i)
    if (primer[i])
      for (int j = 2*i; j < MAX; j += i) primer[j] = false;

  int n;
  while (cin >> n) {
    V = VI(n);
    for (int& x : V) cin >> x;
    R = VI(n, -1);
    cout << f(n - 1) << endl;
  }
}
