/*
Let’s play numerology. Write a program such that, given two numbers n and m, prints all the ways to insert ‘+’ signs into m so that the sum is n.

Input

Input consists of several cases. Every case has two strictly positive natural numbers n and ‍m, each not larger than 1012. Assume that the leftmost digit of n and of m is never zero.

Output

For every case, print all the ways to get n by adding the digits of m as explained above. The solutions must appear in lexicographical order. If no solution exists, state so.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
using vb = vector<bool>;

ll n, sum;
string m;
int sizem;
vb plussign;
bool solved;

ll stringtoll(int x, int y) {
    ll ans = 0;
    for(int i = x; i <= y; ++i) {
        ans *= 10;
        ans += (int)(m[i] - '0');
    }
    return ans;
}

void print() {
    solved = true;
    cout << n << " = ";
    for(int i = 0; i < sizem; ++i) {
        cout << m[i];
        if(i < sizem - 1 and plussign[i]) cout << " + ";
    }
    cout << "\n";
}

void solve(int pos, int lastpos) {
    if(pos == sizem-1) {
        sum += stringtoll(lastpos, pos);
        if(sum == n) print();
        return;
    }
    if(sum > n) return;
    plussign[pos] = true;
    ll tempsum = sum; 
    sum += stringtoll(lastpos, pos);
    solve(pos+1, pos+1);
    sum = tempsum;
    plussign[pos] = false;
    solve(pos+1, lastpos);
}

int main () {
    while(cin >> n >> m) {
        sum = 0;
        sizem = (int)m.size();
        plussign = vb(sizem, false);
        solved = false;
        solve(0, 0);
        if(not solved) cout << "No solution for " << n << ' ' << m << ".\n";
    }
}