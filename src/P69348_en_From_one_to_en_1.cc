/*
Write program that prints all the permutations of { 1, …, n } for a given n.

Input

Input consists of a natural number n > 0.

Output

Print all the permutations of { 1, …, n } in lexicographical order.
*/

//reskoldo73, 2025-09-10

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

vi perm;
vb avail;
int n;

void print() {
    cout << '(';
    for(int i = 0; i < n; ++i) cout << (i ? "," : "") << perm[i]+1;
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
    perm = vi(n);
    avail = vb(n, true);
    solve(0);
}

