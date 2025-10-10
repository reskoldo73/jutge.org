/*
Recent excavations have discovered the rests of an extincted race of pseudo-human primates called Omgillas (not to mistake for gorillas). Among other curiosities, they eated raw fish, slept at least twelve hours a day, and shaved their heads twice a year.

On the other hand, they must knew some basic mathematics, since they used coins with prime values: 2, 3, 5, 7, 11, 13, 17, 19, 23 and 29. This strange choice (for instance, there was no way to buy something of value 1 without change) and the fact that Omgillas were a bit silly caused a lot of confusion and their eventual extintion.

The sistem of coins of Omgillas is original enough to be investigated. Unfortunately, current humans are not much more intelligent. Therefore, a program that helps with this task would be welcome. Take into account that the coins were quite big and heavy, so only a few could be used in each transaction. It is known that the strongest Omgilla, the mythical warrior Obok-Aman, was able to carry just 20 coins.

To sumarize: Write a program such that, given a number of coins c and a value v, prints the number of different ways to get an amount of v with exactly c coins. Assume an infinite suply of coins of every kind: 2, 3, 5, …, 29.

Input

Input begins with the number of cases n, followed by n pairs of natural numbers c and v. Assume 1 ≤ c ≤ 20 and 1 ≤ v ≤ 106.

Output

For every case, print the number of different ways to get a value v with exactly c coins.
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

const vector<int> coins = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

ll solve(int c, int v) {
    // dp[i][j][k] represents ways to make sum j using exactly i coins
    // where k is the index of the largest coin we can use
    vector<vvll> dp(c + 1, vvll(v + 1, vll(coins.size(), 0)));
    
    // Base case: using 0 coins to make 0
    for(int k = 0; k < (int)coins.size(); ++k) {
        dp[0][0][k] = 1;
    }
    
    // For each number of coins
    for(int i = 1; i <= c; ++i) {
        // For each value
        for(int j = 0; j <= v; ++j) {
            // For each maximum coin index we can use
            for(int k = 0; k < (int)coins.size(); ++k) {
                // Skip if current coin is too large
                if(coins[k] > j) continue;
                
                // Either don't use current coin
                if(k > 0) dp[i][j][k] += dp[i][j][k-1];
                
                // Or use current coin (maintaining non-decreasing order)
                dp[i][j][k] += dp[i-1][j-coins[k]][k];
            }
        }
    }
    
    return dp[c][v][coins.size()-1];
}

int main() {
    int n;
    cin >> n;
    
    while(n--) {
        int c, v;
        cin >> c >> v;
        cout << solve(c, v) << endl;
    }
}