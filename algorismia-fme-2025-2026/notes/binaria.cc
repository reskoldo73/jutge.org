// Donada una h i les posicions d'n pobles en ordre,
// cal dir a quina distancia poden quedar tots els pobles de l'hospital mes proper
// si es poden posar fins a h hospitals on es vulgui.
// El cost es O(n * log(resposta)).


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int h, n;
VI V;


bool ok(int dist) {
  int q = 0;
  int pos = V[0] + dist;
  for (int i = 0; i < n; ++i)
    if (abs(V[i] - pos) > dist) {
      if (++q > h) return false; // caldrien mes hospitals dels permesos
      pos = V[i] + dist;
    }
  return ++q <= h;
}


int solu() {
  if (ok(0)) return 0;
  int d = 1;
  while (not ok(d)) d *= 2;
  int e = d/2;
  while (e + 1 < d) { // amb e no es pot, amb d si
    int m = (e + d)/2;
    (ok(m) ? d : e) = m;
  }
  return d;
}


int main() {
  cin >> h >> n;
  V = VI(n);
  for (int& x : V) cin >> x;
  cout << solu() << endl;
}
