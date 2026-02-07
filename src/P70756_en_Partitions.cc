/*
Write a program that, given n different words s1, …, sn and a number ‍p, prints
all the ways to share the words between p subsets.

Input

Input consists of a natural number n > 0, followed by s1, …, sn, followed by a
natural number p > 0.

Output

Print all the ways to share the words between p subsets. The elements of each
set must appear in the same order than in the input. Print an empty line after
each partition.

Observation

Strictly speaking, a partition cannot have empty subsets, but we forget about
that restriction in this exercise.

Information about the checker You can print the solutions to this exercise in
any order.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>

using namespace std;
using vs = vector<string>;
using vvs = vector<vs>;
int n, p;
vs v;
vvs ans;

void print() {
    for(int j = 0; j < p; ++j) {
        cout << "subset " << j + 1 << ": {";
        for(int i = 0; i < (int)ans[j].size(); ++i) cout << (i ? "," : "") << ans[j][i];
        cout << "}\n";
    }
    cout << "\n";
}

void solve(int posv) {
    if(posv == n) return print();
    for(int i = 0; i < p; ++i) {
        ans[i].push_back(v[posv]);
        solve(posv + 1);
        ans[i].pop_back();
    }
}

int main () {
    cin >> n;
    v = vs(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cin >> p;
    ans = vvs(p);
    solve(0);
}
