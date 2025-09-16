/*
Write a program that, given two numbers n and t, prints all the multisets with t ‍numbers that can be made up with {1, …, n}.

Input

Input consists of a natural number n > 0, followed by a natural number t ≥ 0.

Output

Print all the multisets of size t that can be made up with {1, …, n}. The numbers inside each multiset must appear in non-decreasing order.

Information about the checker
You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n, t, sum;
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
    if(sum == t) return print();
    if(pos == n) return;
    for(int i = 0; i <= t - sum; ++i) {
        v[pos] = i;
        sum += i;
        solve(pos+1);
        sum -= i;
        v[pos] = 0;
    }
}

int main () {
    cin >> n >> t;
    v = vi(n, 0);
    sum = 0;
    solve(0);
}