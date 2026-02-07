/*
The statement of this problem is similar to that of problem ‍. But here, the n
weights do not need to be 20, 21, …, 2n−1.

I.e., the problem is: Given n weights, we have to place all the weights on a
balance, one after another, in such a way that the right pan is never heavier
than the left pan. Please compute the number of ways of doing this.

Input

Input consists of several cases, each with the number of weights n followed by n
different weights, all between 1 and 106. Assume 1 ≤ n ≤ 8.

Output

For every case, print the number of correct ways of placing the weights on the
balance. This number will never be larger than 107.
*/

//reskoldo73, 2025-09-22

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

int n, ans, suml, sumr;
vb avail;
vi v;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int pos) {
    if(pos == n) {
        if(sumr <= suml) ++ans;
        return;
    }
    if(suml < sumr) return;
    for(int i = 0; i < n; ++i) {
        if(avail[i]) {
            avail[i] = false;
            suml+=v[i];
            solve(pos+1);
            suml-=v[i];
            sumr+=v[i];
            solve(pos+1);
            sumr-=v[i];
            avail[i] = true;
        }
    }
}

int main() {
    fast_io();
    while(cin >> n) {
        v = vi(n);
        avail = vb(n, true);
        sumr = suml = ans = 0;
        for(int i = 0; i < n; ++i) cin >> v[i];
        solve(0);
        cout << ans << endl;
    }
}