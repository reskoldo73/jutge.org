/*
Write a program that, given a natural number m and n different words s1, …, sn,
prints all the subsets of m elements that can be made up with the words.

Input

Input consists of two natural numbers m and n, followed by s1, …, sn. Assume
n > 0 and 0 ≤ m ≤ n.

Output

Print all the subsets of m words that can be made up with s1, …, sn.

Information about the checker You can print in any order both the solutions and
the elements inside each solution.
*/

//reskoldo73, 2025-09-15

#include <iostream>
#include <vector>
using namespace std;

using vs = vector<string>;

int m, n;
vs v, all;

void print() {
    cout << '{';
    for(int i = 0; i < m; ++i) cout << (i ? "," : "") << v[i];
    cout << "}\n";
}

void solve(int pos) {
    if(m == (int)v.size()) return print();
    if(pos == n or (int)v.size() + (n - pos) < m) return;
    v.push_back(all[pos]);
    solve(pos+1);
    v.pop_back();
    solve(pos+1);
}

int main() {
    cin >> m >> n;
    all = vs(n);
    for(int i = 0; i < n; ++i) cin >> all[i];
    v = vs();
    solve(0);
}
