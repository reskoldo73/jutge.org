/*
For every given natural number n, compute Fn mod10^8 + 7.

Input

Input consists of several n. Assume 0 ≤ n ≤ 105.

Output

For every given n, print Fn mod10^8 + 7.
*/

//reskoldo73, 2025-09-23

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

const int mod = 1e8+7;

vi v;

int f(int x) {
    if(v[x] != -1) return v[x];
    return v[x] = (f(x-1)%mod+f(x-2)%mod)%mod;
}

int main () {
    int n;
    v = vi(1e5+1, -1);
    v[0] = 0;
    v[1] = 1;
    while(cin >> n) {
        cout << f(n) << "\n";
    }
}