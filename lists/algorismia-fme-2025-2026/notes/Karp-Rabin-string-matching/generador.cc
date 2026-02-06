#include <iostream>
#include <cstdlib>

using namespace std;

const string lletra = "ACGT";

int main() {
  int seed, m, n;
  cin >> seed >> m >> n;
  srand(seed);
  for (int i = 0; i < m; ++i) cout << lletra[rand()%4];
  cout << endl;
  for (int j = 0; j < n; ++j) cout << lletra[rand()%4];
  cout << endl;
}
