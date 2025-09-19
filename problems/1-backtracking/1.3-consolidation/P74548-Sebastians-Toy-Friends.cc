/*
J. ‍F. ‍Sebastian is a genetic designer working for Tyrell Corporation. In his spare time, he makes small humanoid robots that are his toy-friends. Sebastian currently has n heads, n ‍bodies and n pairs of legs, and he wonders how these parts can be distributed to construct n toy-friends.

Heads are codified with uppercase letters (starting at A), bodies with digits (starting at 0), and legs with lowercase letters (starting at a). This way, a toy-friend can be codified with three characters, and any distribution of the 3n pieces can be described with n ‍triples of characters. For instance, a possible distribution for n = 2 is A1b–B0a: one robot (A1b) consists of the first head, the second body and the second pair of legs, while the other robot (B0a) consists of the second head, the first body and the first pair of legs. The other possible distributions are A0a–B1b, A0b–B1a and A1a–B0b.

Input

Input consists of several cases, each with a positive integer n. A special case with n = 0 ends the input.

Output

For every case, print its number starting at one, followed by all the possible distributions in increasing order. The codifications of the toy-friends inside each distribution must also appear in increasing order, separated with dashes.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;

int n;
vi v;
vvb avail;

void print() {
    for(int i = 0; i < n; ++i) cout << (i ? "-" : "") << (char)(i + 'A') << v[2*i] << (char)(v[2*i+1] + 'a');
    cout << "\n";
}

void solve(int pos) {
    if(pos == 2*n) return print();
    int mod = pos%2;
    for(int i = 0; i < n; ++i) {
        if(avail[mod][i]) {
            v[pos] = i;
            avail[mod][i] = false;
            solve(pos+1);
            avail[mod][i] = true;
        }
    }
}

int main () {
    int count = 0;
    while(cin >> n and n != 0) {
        v = vi(2*n);
        avail = vvb(2, vb(n, true));
        cout << "Case " << ++count << "\n";
        solve(0);
    }
}