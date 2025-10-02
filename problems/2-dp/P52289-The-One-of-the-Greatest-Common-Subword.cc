/*
Some problems are so classic that barely need a statement. For this one, we ask you to compute the longest subword that two given words have in common. In case of a tie, print the smallest one in alphabetical order.

Input

Input consists of several cases, each with two non-empty words w1 and w2 made up of at most 500 lowercase letters.

Output

For every case, print the longest common subword. In case of a tie, print the smallest one in alphabetical order.

Observation

There are very fast algorithms to solve this problem. Here, we settle for one that takes time proportional to n1· n2, where n1 and n2 are the lengths of w1 and w2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;

string s, t, best;
vvi memo;
int maxlen;


int solve(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == t[j]) {
        int len = 1 + solve(i-1, j-1);
        memo[i][j] = len;

        if(len > maxlen) {
            maxlen = len;
            best = s.substr(i-len+1, len);
        }
        else if(len == maxlen) {
            string temp = s.substr(i-len+1, len);
            if(temp < best) best = temp;
        }
        return len;
    }
    else return memo[i][j] = 0;
}

int main () {
    while(cin >> s >> t) {
        int n = s.size();
        int m = t.size();
        memo = vvi(n+1, vi(m+1, -1));
        maxlen = 0;
        best = "";
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) solve(i, j);

        cout << best << "\n";
    }
}