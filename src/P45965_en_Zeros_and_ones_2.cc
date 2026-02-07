/*
Write a program to print all the combinations of n − o zeros and o ones, for
some given n and o.

Input

Input consists of n and o, two natural numbers such that n > 0 and 0 ≤ o ≤ n.

Output

Print all the combinations of n − o zeros and o ones, one per line and in
lexicographical order.
*/

//reskoldo73, 2025-09-15

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;

int n, zeros, ones;
vb v;

void print() {
    for(int i = 0; i < n; ++i) cout << (i ? " " : "") << v[i];
    cout << "\n";
}

void solve(int pos) {
    if(zeros < 0 or ones < 0) return;
    if(pos == n) return print();
    v[pos] = 0;
    --zeros;
    solve(pos+1);
    ++zeros;
    v[pos] = 1;
    --ones;
    solve(pos+1);
    ++ones;
}

int main() {
    cin >> n >> ones;
    zeros = n - ones;
    v = vb(n);
    solve(0);
}

