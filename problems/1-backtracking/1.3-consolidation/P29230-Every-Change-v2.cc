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

//check high halstead diff

const vi val = {50, 20, 10, 5, 2, 1};
vi v(6);

void print() {
    bool first = true;
    for(int i = 0; i < 6; ++i) {
        int n = v[i];
        while(n--) {
            if(not first) cout << ' ';
            first = false;
            cout << val[i];            
        }
    }
    cout << "\n";
}

void solve(int pos, int n) {
    if(pos == 5) {
        v[5] = n;
        return print();
    }
    int maxc = n / val[pos];
    for(int i = maxc; i >= 0; --i) {
        v[pos] = i;
        solve(pos+1, n - i*val[pos]);
    }
}

int main () {
    int n;
    while(cin >> n) {
        solve(0, n);
        cout << "\n";
    }
}