/*
For every given pair of natural numbers n and m, compute Fn modm.

Input

Input consists of several pairs of n and m. Assume 0 ≤ n ≤ 1000 and 2 ≤ m ≤ 108.

Output

For every given pair, print Fn modm.
*/

//reskoldo73, 2025-09-28

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vll = vector<ll>;

const int maxn = 1000;

ll solve(int n, int m) {
    if(n<2) return n;
    vll fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; ++i) fib[i] = (fib[i-1] + fib[i-2])%m;
    return fib[n];
}

int main () {
    int n, m;
    while(cin >> n >> m) cout << solve(n, m) << "\n";
}
