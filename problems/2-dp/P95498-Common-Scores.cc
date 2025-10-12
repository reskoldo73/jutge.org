/*
Two friends, Arthur and Bob, are playing computer games, and they have decided to store their scores. When they stop playing, Arthur and Bob want to determine the length of the maximum subsequence of scores that they have in common.

For instance, if the scores of Arthur are [8, 12, 6, 9, 2], and those of Bob are [12, 6, 8, 2], then the maximum subsequence that they have in common is [12, 6, 2], which has length 3. Note that a subsequence does not have to be made up of consecutive elements, but we must preserve the order of the scores.

Input

Input consists of several cases. Each case begins with two numbers 0≤ M≤ 1000 and 0≤ N≤ 1000, representing the length of the subsequences of Arthur and Bob, respectively. Follow the M numbers of Arthur, and the N numbers of Bob. All the numbers are natural.

Output

For every case, print the length of the longest common subsequence.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi a, b;
vvi memo;

int solve(int i, int j) {
    if(i < 0 or j < 0) return 0;
    if(memo[i][j] != -1)
        return memo[i][j];
    if(a[i] == b[j]) 
        return memo[i][j] = 1 + solve(i-1, j-1);
    return memo[i][j] = max(solve(i-1, j), solve(i, j-1));
}

int main () {
    int m, n;
    while(cin >> m >> n) {
        a = vi(m);
        b = vi(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        memo = vvi(m, vi(n, -1));
        cout << solve(m-1, n-1) << "\n";
    }
}