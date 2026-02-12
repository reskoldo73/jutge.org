//solució oficial

#include <iostream>
using namespace std;
// c es digit
// retorna l'expressio representada despres de c (entre [])
string expressio(char c) {
int rep = c - '0';
cin >> c;
// nombre de repeticions
// parentesi [
string s;
while (cin >> c and c != ']') {
if (islower(c)) s += c;
else s += expressio(c);
}// processar contingut fins ]
// lletra => acumular string
// digit => nova (sub)expressio
string res;
for (int i = 0; i < rep; ++i) res += s;
return res;// concatenar rep vegades
}
int main() {
char c;
while (cin >> c) cout << expressio(c) << endl;
}