/*
Write a program that, given n different words s1, …, sn, prints all the permutations that can be made up with the words.

Input

Input consists of a number n > 0, followed by s1, …, sn.

Output

Print all the permutations that can be made up with s1, …, sn.

Information about the checker
You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;

vi perm;
vb avail;
int n;

vs words;

void print() {
    cout << '(';
    for(int i = 0; i < n; ++i) cout << (i ? "," : "") << words[perm[i]];
    cout << ")\n";
}

void solve(int pos) {
    if(pos == n) return print();
    for(int i = 0; i < n; ++i) {
        if(avail[i]) {
            avail[i] = false;
            perm[pos] = i;
            solve(pos+1);
            avail[i] = true;
        }
    }
}

int main () {
    cin >> n;
    words = vs(n);
    for(int i = 0; i < n; ++i) cin >> words[i];
    perm = vi(n);
    avail = vb(n, true);
    solve(0);
}

