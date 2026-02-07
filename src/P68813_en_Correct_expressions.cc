/*
In this problem we consider the expressions defined as follows:

Every variable is a correct expresion; if x is a correct expression, so is (x);
if x1 and x2 are correct expressions, so are (x1) − (x2); nothing else is a
correct expression. For instance, if the set of variables is A, B, C, these are
some correct expressions:

A    (A)    ((C))    (A)−(B)    ((A)−(B))−(A) Write a program that, given two
numbers n and m, prints the number of correct expressions of length exactly n
that can be made up with m variables.

For instance, for n =7 and m=2 the result should be 6, corresponding to

(((A)))    (((B)))    (A)−(A)    (A)−(B)    (B)−(A)    (B)−(B) Input

Input consists of several cases, each with two natural numbers n and m between 1
and 25.

Output

For every case, print the number of correct expressions of length exactly n that
can be made up with m variables. This number will always be smaller than 109.
*/

//reskoldo73, 2025-10-02

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int maxn = 25;
const int maxm = 25;


vvi memo;

// Returns the number of correct expressions of length n with m variables
int solve(int n, int m) {
    if (n < 1 || m < 1 || n%2 == 0) return 0;
    if (memo[n][m] != -1) return memo[n][m];
    int &res = memo[n][m] = 0;;
    // Case 1: (x), where x is a correct expression of length n-2
    res += solve(n-2, m);
    // Case 2: (x1)-(x2), where x1 and x2 are correct expressions
    // (x1) is length l, (x2) is length r, so l + r + 5 = n
    for (int l = 1; l <= n-6; l += 2) {
        int r = n - 5 - l;
        if (r >= 1 && r % 2 == 1) {
            res += solve(l, m) * solve(r, m);
        }
    }
    return res;
}

int main() {
    memo = vvi(maxn+1, vi(maxm+1, -1));
    for(int j = 0; j <= maxm; ++j) memo[1][j] = memo[3][j] = memo[5][j] = j;
    int n, m;
    while(cin >> n >> m) cout << solve(n, m) << endl;
}