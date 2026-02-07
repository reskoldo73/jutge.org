/*
Write a program that prints the number of sequences of length n made up of only
zeros and ones that do not contain two consecutive zeros nor three consecutive
ones.

For instance, there are 7 sequences for n = 5:

01010   01011   01101   10101   10110   11010   11011 Input

Input consists of several natural numbers n, each between 0 and 150.

Output

For every n, print the required number.
*/

//reskoldo73, 2025-10-02

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;

//revise, high ccn

const int maxn = 150;
vvvll memo;


ll solve(int n, int i, int j) {
    if(n < 2) return n+1;
    if(memo[n][i][j] != 0) return memo[n][i][j];
    if(i == 0) {
        if(j == 0) memo[n][0][0] = solve(n, 0, 1) + solve(n, 1, 0) + solve(n, 1, 1);
        else memo[n][0][1] = solve(n-1, 1, 0);
    }
    else {
        if(j == 0) memo[n][1][0] = solve(n-1, 0, 1) + solve(n-1, 1, 1);
        else memo[n][1][1] = solve(n-1, 0, 1);
    }
    return memo[n][i][j];
}

int main() {
    memo = vvvll(maxn + 1, vvll(2, vll(2, 0)));
    memo[2][0][1] = memo[2][1][0] = memo[2][1][1] = 1;
    memo[2][0][0] = memo[2][0][1] + memo[2][1][0] + memo[2][1][1];
    int n;
    while(cin >> n) cout << solve(n, 0, 0) << endl;
}