// Sudoku


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;


VVI S(9, VI(9));
VVI fila, colu;
VVVI quad;


void escriu() {
  cout << endl;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j)
      cout << (j ? " " : "") << S[i][j];
    cout << endl;
  }
}


bool f(int i, int j) {
  if (j == 9) return f(i + 1, 0);

  if (i == 9) {
    escriu();
    return true;
  }

  if (S[i][j]) return f(i, j + 1);

  for (int x = 1; x <= 9; ++x)
    if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
      S[i][j] = x;
      if (f(i, j + 1)) return true;
      S[i][j] = 0;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
    }
  return false;
}


int main() {
  int t;
  cin >> t;
  cout << t << endl;
  while (t--) {
    fila = colu = VVI(9, VI(10, false));
    quad = VVVI(3, VVI(3, VI(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') S[i][j] = 0;
        else {
          int x = c - '0';
          S[i][j] = x;
          fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
        }
      }

    f(0, 0);
  }
}
