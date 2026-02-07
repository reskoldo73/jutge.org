/*
Some problems are so classic that barely need a statement. For this one, please
compute the minimum cost to insert letters into two words w1 and w2 to make them
identical. Both words are made up of only letters chosen among the n smallest
lowercase letters (for instance, for n=4, the alphabet is {a, b, c, d}). For
every letter (call it x), inserting an x in any place in any word has cost Ix.

Input

Input consists of several cases. Each case begins with 2≤ n≤ 26, followed by n
strictly positive natural numbers Ia, Ib, Ic, …. Follow two words w1 and w2 made
up of between 1 and 1000 lowercase letters chosen among the n smallest letters.
Assume 1≤ Ix≤ 1000 for every letter x.

Output

For every case, print the minimum cost to make w1 and w2 identical.
*/

//reskoldo73, 2025-10-14

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi costs;
vvi memo;
string s, t;

int solve(int i, int j) {
    if(i < 0 and j < 0) return 0;
    if(i < 0) return costs[t[j]-'a'] + solve(i, j-1);
    if(j < 0) return costs[s[i]-'a'] + solve(i-1, j);

    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == t[j]) return memo[i][j] = solve(i-1, j-1);
    
    return memo[i][j] = min(costs[s[i]-'a'] + solve(i-1, j), costs[t[j]-'a'] + solve(i, j-1));
    
} 

int main () {
    costs = vi(26, 0);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; ++i) cin >> costs[i];
        cin >> s >> t;
        int ssize = s.size();
        int tsize = t.size();
        memo = vvi(ssize, vi(tsize, -1));
        cout << solve(ssize-1, tsize-1) << "\n";
    }
}