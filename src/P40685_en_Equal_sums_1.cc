/*
Write a program that, given an integer number s and n integer numbers x1, …, xn,
prints all the subsets (maybe with repeated numbers, but using every xi at most
once) whose sum is exactly s.

Input

Input consists of an integer number s, followed by a number n > 0, followed by
x1, …, xn.

Output

Print all the subsets whose sum is s that can be made up with x1, …, xn.

Information about the checker You can print in any order both the solutions and
the elements inside each solution.

Hint

For this exercise, simple backtracking solutions are accepted. No optimizations
are required.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;

int s, n, sum;
vi v, inp;

void print() {
    cout << '{';
    for(int i = 0; i < (int)v.size(); ++i) cout << (i ? "," : "") << v[i];
    cout << "}\n";
}

void solve(int pos) {
    if(pos == n and sum == s) return print();
    if(pos == n) return;

    v.push_back(inp[pos]);
    sum += inp[pos];
    solve(pos+1);
    sum -= inp[pos];
    v.pop_back();
    solve(pos+1);
}

int main () {
    cin >> s >> n;
    inp = vi(n);
    for(int i = 0; i < n; ++i) cin >> inp[i];
    sort(inp.begin(), inp.end());
    v = vi();
    sum = 0;
    solve(0);
}