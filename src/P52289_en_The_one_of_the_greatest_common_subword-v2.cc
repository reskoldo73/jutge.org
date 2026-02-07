/*
Some problems are so classic that barely need a statement. For this one, we ask
you to compute the longest subword that two given words have in common. In case
of a tie, print the smallest one in alphabetical order.

Input

Input consists of several cases, each with two non-empty words w1 and w2 made up
of at most 500 lowercase letters.

Output

For every case, print the longest common subword. In case of a tie, print the
smallest one in alphabetical order.

Observation

There are very fast algorithms to solve this problem. Here, we settle for one
that takes time proportional to n1· n2, where n1 and n2 are the lengths of w1
and w2.
*/

//reskoldo73, 2025-10-07

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

string s, t;
int n, m;
vvi memo;


int solve(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == t[j]) return memo[i][j] = 1 + solve(i-1, j-1);
    else return memo[i][j] = 0;
}

string find(int len) {
    string best = "";
    bool found = false;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(solve(i, j) == len) {
                string temp = "";
                for(int k = len-1; k>=0; --k) {
                    temp += s[i-k];
                }
                if(temp < best or not found) best = temp;
                found = true;
            }
        }
    }
    return best;}

int main () {
    while(cin >> s >> t) {
        n = s.size();
        m = t.size();
        memo = vvi(n+1, vi(m+1, -1));
        int maxlen = 0;
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) 
                maxlen = max(solve(i, j), maxlen);
        
        cout << find(maxlen) << endl;
    }
}