/*
Write a program such that, for every given natural number n, prints all the different ways to obtain n cents with the euro system of coins (1 cent, 2 cents, 5 cents, 10 cents, 20 cents, and 50 cents).

Input

Input consists of a sequence of natural numbers 1 ≤ n ≤ 50.

Output

For every n, print all the ways to obtain n cents, each one in a different line. The numbers of each line must appear in nonincreasing order. The solutions for every n must appear in reverse lexicographical order. Print an empty line after the output for each case.

Observation

A simple backtracking program that computes the result for every given n (even if repeated) is fast enough for this problem.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

//inefficient, high Halstead diff and high ccn

const vi val = {50, 20, 10, 5, 2, 1};
vi v;

void print() {
    for(int i = 0; i < (int)v.size(); ++i) cout << (i ? " " : "") << v[i];
    cout << "\n";
}

void solve(int pos, int n) {
    if(pos == 5) {
        for(int i = 0; i < n; ++i) v.push_back(1);
        print();
        for(int i = 0; i < n; ++i) v.pop_back();
        return;
    }
    int maxc = n / val[pos];
    for(int i = maxc; i >= 0; --i) {
        for(int k = 0; k < i; ++k) v.push_back(val[pos]);
        solve(pos+1, n - i*val[pos]);
        for(int k = 0; k < i; ++k) v.pop_back();
    }
}

int main () {
    int n;
    while(cin >> n) {
        v = vi();
        solve(0, n);
        cout << "\n";
    }
}