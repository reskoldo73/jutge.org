/*
Write a program that, given n different words s1, …, sn, prints all the subsets
that can be made up with the words.

Input

Input consists of a number n > 0, followed by s1, …, sn.

Output

Print all the subsets that can be made up with s1, …, sn.

Information about the checker You can print in any order both the solutions and
the elements inside each solution.
*/

//reskoldo73, 2025-09-15

#include <iostream>
#include <vector>
using namespace std;

using vs = vector<string>;
vs v, all;
int n;

void print() {
    cout << "{";
    for(int i = 0; i < (int)v.size(); ++i) cout << (i ? "," : "") << v[i];
    cout << "}\n";
}

void solve(int pos) {
    print();
    for(int i = pos; i < n; ++i) {
        v.push_back(all[i]);
        solve(i+1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    all = vs(n);
    for(int i = 0; i < n; ++i) cin >> all[i];
    v = vs();
    solve(0);
}
