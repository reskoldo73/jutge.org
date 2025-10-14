/*
Some problems are so classic that barely need a statement. For this one, please compute the minimum cost to insert letters into two words w1 and w2 to make them identical. Both words are made up of only letters chosen among the n smallest lowercase letters (for instance, for n=4, the alphabet is {a, b, c, d}). For every letter (call it x), inserting an x in any place in any word has cost Ix.

Input

Input consists of several cases. Each case begins with 2≤ n≤ 26, followed by n strictly positive natural numbers Ia, Ib, Ic, …. Follow two words w1 and w2 made up of between 1 and 1000 lowercase letters chosen among the n smallest letters. Assume 1≤ Ix≤ 1000 for every letter x.

Output

For every case, print the minimum cost to make w1 and w2 identical.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi costs;
vvi memo;
string s, t;

int solve(int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    
}

int main () {
    costs = vi(26, 0);
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; ++i) cin >> costs[i];
        cin >> s >> t;
        int size = s.size();
        cout << solve(size-1, size-1);

    }
}