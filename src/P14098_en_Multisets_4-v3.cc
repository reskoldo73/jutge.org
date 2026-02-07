/*
Write a program that, given four natural numbers n, x, y and t, prints all the
multisets with t ‍numbers that can be made up with {1, …, n}, in such a way that
every number appears between x and y times.

Input

Input consists of a natural number n > 0, followed by a natural number x ≥ 0,
followed by a natural number y > x, followed by a natural number t ≥ 0. Assume
nx ≤ t ≤ ny.

Output

Print all the multisets of size t that can be made up with {1, …, n}, using each
number between x and y times. The numbers inside each multiset must appear in
non-decreasing order.

Information about the checker You can print the solutions to this exercise in
any order.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n, x, y, t, sum;
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
    if(sum == t and pos == n) return print();
    if(pos == n or (sum + x*(n-pos) > t) or (sum + y*(n-pos) < t)) return;
    for(int i = x; i <= t - sum and i <= y; ++i) {
        v[pos] = i;
        sum += i;
        solve(pos+1);
        sum -= i;
    }
}

int main () {
    cin >> n >> x >> y >> t;
    v = vi(n);
    sum = 0;
    solve(0);
}