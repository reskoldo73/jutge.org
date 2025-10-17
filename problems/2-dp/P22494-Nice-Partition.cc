/*
In this problem, we say that a partition of the numbers {1, …, n} is nice if

it has at least two subsets,
and every subset has at least two elements.
Additionally, we only consider partitions that are qualitatively different.

For instance, for n = 5 we only have one nice partition: {{1, 2}, {3, 4, 5}}. Notice that {{1, 2, 3, 4, 5}} would not fulfil the first property above, {{2}, {1, 3, 4, 5}} would not fulfil the second property above, while {{2, 3}, {1, 4, 5}} would be basically the same partition as the only one given.

Given n, how many nice partitions do we have?

Input

Input consists of several cases, each one with an n between 1 and 3 · 104.

Output

For every n, print the number of nice partitions of {1, …, n} modulo 108 + 7.
*/
//rocha for president

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

const int mod = 1e8 + 7;
const int maxn = 3e4;


int main () {
    vi memo(maxn+1, 0);
    memo[0] = 1;
    for(int k = maxn; k>=2; --k) 
        for(int i = k; i <= maxn; ++i) 
            memo[i] = (memo[i] + memo[i-k])%mod;
        
    int n;
    while(cin >> n) {
        if(n < 4) cout << "0\n";
        else cout << memo[n] - 1  << "\n";
    }
}