/*
Write a program that, given three numbers n, x and y, prints all the multisets
that can be made up with {1, …, n}, in such a way that every number appears
between x and y times.

Input

Input consists of a natural number n > 0, followed by a natural number x ≥ 0,
followed by a natural number y > x.

Output

Print all the multisets that can be made up with {1, …, n}, using each number
between x and y times. The numbers inside each multiset must appear in
non-decreasing order.

Information about the checker You can print the solutions to this exercise in
any order.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n, x, y;
vi v;

void print() {
    cout << '{';
    bool comma = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < v[i]; ++j) {
            cout << (comma ? "," : "") << i + 1;
            comma = true;
        }
    }
    cout << "}\n";
}

void solve(int pos) {
    if(pos == n) return print();
    for(int i = x; i <= y; ++i) {
        v[pos] = i;
        solve(pos+1);
    }
}

int main () {
    cin >> n >> x >> y;
    v = vi(n);
    solve(0);
}