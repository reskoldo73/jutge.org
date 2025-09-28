/*
Write a program that prints the number of sequences of length n made up of only zeros and ones that do not contain two consecutive zeros nor three consecutive ones.

For instance, there are 7 sequences for n = 5:

01010   01011   01101   10101   10110   11010   11011
Input

Input consists of several natural numbers n, each between 0 and 150.

Output

For every n, print the required number.
*/

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vb = vector<bool>;

//incredibly wrong
//think that if a n sequence can split, both n+1 sequences can't
//and that a n sequence can split iff it ends with 01

vi prime;
vb erat;
vll ans;


ll solve(int n) {
    if(ans[n] == -1) return ans[n] = solve(n-1) + prime[(n-1)/2];
    else return ans[n];
}

int main() {
    prime = vi();
    erat = vb(400, true);
    for(int i = 2; i < 400; ++i) {
        if(erat[i]) for(int j = 2; j*i < 400; ++j) erat[j*i] = false;
    }
    for(int i = 0; i < 400; ++i) if(erat[i]) prime.push_back(i);
    ans = vll(150+1, -1);
    for(int i = 0; i < 3; ++i) ans[i] = i+1;
    int n;
    while(cin >> n) cout << solve(n) << endl;
}