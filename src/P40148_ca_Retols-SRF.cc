//solució oficial

#include <iostream>
#include <vector>
using namespace std;
using VS = vector<string>;
void posa(int k, const string& s, VS& M) {
int ini = 5*k + 2;
for (int i = 0; i < 5; ++i) {
for (int j = 0; j < 3; ++j) {
if (s[3*i+j] == '1') M[i][ini+j] = 'O';
}
}
}
int main() {
int n;
while (cin >> n) {
int mida = 5*n + 2;
VS M(5, string(mida, ' '));
for (int k = 0; k < n; ++k) {
string s;
cin >> s;
posa(k, s, M);
}
cout << '*' << string(mida, '-') << '*' << endl;
for (int i = 0; i < 5; ++i) cout << '|' << M[i] << '|' << endl;
cout << '*' << string(mida, '-') << '*' << endl;
}
}