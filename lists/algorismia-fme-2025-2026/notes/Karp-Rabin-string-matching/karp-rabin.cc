#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int num_falsos_positius = 0;

string paraula; // la paraula a buscar
string text;    // el text on buscar
int base = 256; // mida de l'alfabet

int m; // llargada de la paraula
int n; // llargada del text

const int MIN_MODUL = 10000; // modul minim requerit
const int MAX_MODUL = 20000; // modul maxim requerit

// per tenir garantia de cost esperat Theta(n + m)
// cal escollir:
// MIN_MODUL = Omega(n*m^2)
// MAX_MODUL = O(n*m^2)

bool es_primer(int p) {
  // versio escolar (es a dir, lenta)
  if (p == 2) return true;
  if (p <= 1 or p%2 == 0) return false;
  for (int q = 3; q*q <= p; q += 2) {
    if (p%q == 0) return false;
  }
  return true;
}

bool iguals(int j) {
  for (int i = 0; i < m; ++i) {
    if (paraula[i] != text[j+i]) return false;
  }
  return true;
}

int busca_ineficient() {
  for (int j = 0; j < n-m+1; ++j) {
    if (iguals(j)) return j;
  }
  return -1;
}

int busca_Karp_Rabin(int modul) {
  int p = modul;
  int b = base;

  int hp = paraula[0];
  int h = text[0];
  int pot = b;
  for (int i = 1; i < m; ++i) {
    hp = (hp*b + paraula[i])%p;
    h = (h*b + text[i])%p;
    pot = (pot*b)%p;
  }

  for (int j = 0; j < n-m+1; ++j) {
    cout << "comparant " << h << " amb " << hp << endl;
    if (h == hp) {
      cout << "  comprovant posicio " << j << endl;
      if (iguals(j)) return j;
      else num_falsos_positius++;
    }
    h = (h*b - text[j]*pot + text[j+m])%p;
    if (h < 0) h += p;
  }

  return -1;
}

int computa_modul() {
  int seed = time(0);
  cout << "llavor: " << seed << endl;
  srand(seed);
  int modul = 1;
  int intents = 0;
  while (not es_primer(modul)) {
    modul = MIN_MODUL + rand()%(MAX_MODUL - MIN_MODUL + 1);
    intents++;
  }
  cout << "modul: " << modul << endl;
  cout << "intents: " << intents << endl;
  return modul;
}


int main() {
  cin >> paraula;
  cin >> text;
  m = paraula.size();
  n = text.size();

  int modul = computa_modul();
  int posicio = busca_Karp_Rabin(modul);
  cout << "numero de col-lisions: " << num_falsos_positius << endl;
  if (posicio >= 0) cout << posicio << endl;
  else cout << "no hi es" << endl;
}

