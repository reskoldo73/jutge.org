/*
Write a program that, given an integer number s and n integer numbers x1, …, xn,
prints the subset (maybe with repeated numbers, but using every xi at most once)
lexicographically largest among those whose sum is s.

Input

Input consists of an integer number s, followed by a number n > 0, followed by
x1, …, xn.

Output

Print, with the elements sorted non-increasingly, the subset that is greatest in
lexicographical order among those that can be made up with x1, …, xn and whose
sum is s. If there is none, print “no solution”.

Hint

Sort the given numbers.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;

int s, n, sum;
vi v, inp;


bool solve(int pos) {
    if(pos == n and sum == s) return true;
    if(pos == n) return false;
    v.push_back(inp[pos]);
    sum += inp[pos];
    if(solve(pos+1)) return true;
    sum -= inp[pos];
    v.pop_back();
    if(solve(pos+1)) return true;
    return false;
}

int main () {
    cin >> s >> n;
    inp = vi(n);
    for(int i = 0; i < n; ++i) cin >> inp[i];
    sort(inp.rbegin(), inp.rend());
    v = vi();
    sum = 0;
    if(solve(0)) {
        cout << '{';
        for(int i = 0; i < (int)v.size(); ++i) cout << (i ? "," : "") << v[i];
        cout << "}\n";
    }
    else cout << "no solution\n";
}