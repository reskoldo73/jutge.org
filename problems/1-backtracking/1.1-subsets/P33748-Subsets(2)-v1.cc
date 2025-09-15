/*
Write a program that, given a natural number m and n different words s1, …, sn, prints all the subsets of m elements that can be made up with the words.

Input

Input consists of two natural numbers m and n, followed by s1, …, sn. Assume n > 0 and 0 ≤ m ≤ n.

Output

Print all the subsets of m words that can be made up with s1, …, sn.

Information about the checker
You can print in any order both the solutions and the elements inside each solution.
*/

#include <iostream>
#include <vector>
using namespace std;

using vs = vector<string>;
using vb = vector<bool>;

int zeros, ones, n;
vs all;
vb v;

void print() {
    cout << '{';
    bool first = true;
    for(int i = 0; i < n; ++i) {
        if(v[i]) {
            if(not first) cout << ',';
            first = false;
            cout << all[i];
        }
    }
    cout << "}\n";
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
    cin >> ones >> n;
    zeros = n - ones;
    all = vs(n);
    for(int i = 0; i < n; ++i) cin >> all[i];
    v = vb(n);
    solve(0);
}
