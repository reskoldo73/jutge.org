/*
At this stage, you surely already know that some problems are so classic that blah, blah, blah. Nothing new with this problem. Now, we ask you to compute the minimum cost to insert letters into or to modify letters from two words w1 and w2 to make them identical. Both words are made up of only letters chosen among the n smallest lowercase letters (for instance, for n=4, the alphabet is {a, b, c, d}). For every letter (call it x), inserting an x in any place in any word has cost Ix. The cost to transform a letter x into a letter y is given by ⌈(Ix+Iy)/4⌉, i.e., a fourth part, ceiling, of the sum fo the insertion costs Ix and Iy.

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

const int maxcost = 1000;

vi costs;
vvi trans;
int mini;

vvi memo;
string s, t;

inline int lowtoint(char c){return (int)(c-'a');} 

int solve(int i, int j) {
    if(i < 0 and j < 0) return 0;
    if(i < 0) return costs[lowtoint(t[j])] + solve(i, j-1);
    if(j < 0) return costs[lowtoint(s[i])] + solve(i-1, j);

    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == t[j]) return memo[i][j] = solve(i-1, j-1);

    return memo[i][j] = min( 
        min( 
            (costs[lowtoint(s[i])] + solve(i-1, j)), 
            (costs[lowtoint(t[j])] + solve(i, j-1)) 
        ), 
        (trans[lowtoint(s[i])][lowtoint(t[j])] + solve(i-1, j-1))
    );

}

int main () {
    int n;
    while(cin >> n) {
        costs = vi(n);
        mini = 0;
        int mincost = maxcost+1;
        for(int i = 0; i < n; ++i) {
            int& temp = costs[i];
            cin >> temp;
            if(temp < mincost) {
                mini = i;
                mincost = temp;
            }
        }
        trans = vvi(n, vi(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                trans[i][j] = (costs[i] + costs[j] + 3) / 4;
            }
        }
        for(int i = 0; i < n; ++i) costs[i] = min(costs[i], mincost + (costs[i] + costs[mini] + 3)/4);
        cin >> s >> t;
        int ssize = s.size();
        int tsize = t.size();
        memo = vvi(ssize, vi(tsize, -1));
        cout << solve(ssize-1, tsize-1) << "\n";
    }
}