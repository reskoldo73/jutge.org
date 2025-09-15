/*
Write a backtracking program to print all the combinations of z zeros and o ones such that z + o = n, for a given n.

Input

Input consists of a natural number n > 0.

Output

Print all the combinations of z zeros and o ones such that z + o = n, one per line and in lexicographical order.

Observation

Although a backtracking program is not really necessary to solve this exercise, implement it anyway for the sake of practice.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;

int n;
vb v;

void print() {
    for(int i = 0; i < n; ++i) cout << (i ? " " : "") << v[i];
    cout << "\n";
}

void solve(int pos) {
    if(pos == n) return print();
    v[pos] = 0;
    solve(pos+1);
    v[pos] = 1;
    solve(pos+1);
}

int main() {
    cin >> n;
    v = vb(n);
    solve(0);
}
