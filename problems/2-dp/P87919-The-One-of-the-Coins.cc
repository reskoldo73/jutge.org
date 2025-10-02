/*
Perhaps you have read that some problems are so classic that they barely need a statement. For this one, given a collection of n coins with different values and a target amount A, we ask you to indicate the way to add up to A by using coins of the largest possible values. In particular, a way is better than another one if the former uses more coins of the largest value; in the event of a tie, if it uses more coins of the second largest value, etc.

Input

Input consists of several cases. Each case begins with the number of coins n between 1 and ‍100, followed by n different integer numbers v1, …, vn, where 1≤ vi≤ 10000. Finally, we have an integer number 1≤ A≤ 100000.

Output

For every case, print in non-increasing order the necessary coins to get A, choosing the combination with coins of largest value in case of a tie. If there is no solution, print −1.
*/

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int A;
vi coins;

int solve(int sum, int pos) {
    
}

int main () {
    int n;
    cin >> n;
    coins = vi(n);
    for(int& x : coins) cin >> x;
    cin >> A;
}