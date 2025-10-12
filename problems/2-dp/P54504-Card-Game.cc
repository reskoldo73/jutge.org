/*
You are playing a card game with a friend. For this game only the suit of the cards matters. The four suits are clubs, diamonds, hearts and spades, with the following values:

||
Suit	    Symbol	Value
Clubs	    ♣	    1
Diamonds	♦	    5
Hearts	    ♥	    8
Spades	    ♠	    14
||
Your friend selects a number n, and you must show cards whose total value equals n, by using the minimum possible number of cards. Assume that you have an unlimited number of cards of each suit.

Input

Input consists of several cases, each one with a natural number n between 0 and 500000. Input ends with a −1.

Output

For every n, print the corresponding result.
*/

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

const int maxn = 500000;
const vi val = {1, 5, 8, 14};
const int valsize = val.size();
vi memo;

int solve(int n) {
    if(n < 0) return maxn;
    if(memo[n] != -1) return memo[n];
    int minn = solve(n-val[0]);
    for(int i = 1; i < valsize; ++i) minn = min(minn, solve(n-val[i]));
    return memo[n] = 1+minn;
}

int main () {
    memo = vi(maxn+1, -1);
    memo[0] = 0;
    for(int x : val) memo[x] = 1;

    int n;
    while(cin >> n and n != -1) {
        cout << solve(n) << "\n";
    }
}