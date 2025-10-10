/*
Write a program that computes how many strictly increasing subsequences with at least two letters are contained in a given word. For instance, the word arrow (we have written the second r in bold italics to distinguish it) contains the increasing subsequences arw, ar, arw, ar, aow, ao, aw, rw, rw and ow.

Input

Input consists of several cases, each with a word made up of between 1 and 100 lowercase letters.

Output

For every case, print the number of strictly increasing subsequences with at least two letters contained in the word. That number will always be less than 109.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

string s;
int n;
vi memo;

int solve(int pos) {
    if(memo[pos] != -1) return memo[pos];
    memo[pos] = 0;
    for(int i = 0; i < pos; ++i) {
        if(s[i] < s[pos]) memo[pos] += 1 + solve(i);
    }
    return memo[pos];
}


int main () {
    while(cin >> s) {
        n = s.size();
        memo = vi(n, -1);
        memo[0] = 0;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            ans += solve(i);
        }
        cout << ans << "\n";
    }
}