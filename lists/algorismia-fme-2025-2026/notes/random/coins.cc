#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;

vi coins;
vvll c;

// ways of adding up to x with the i first coins

ll f(int x, int i) {
    if(x<0) return 0;
    ll& res = c[x][i];
    if(res != -1) return res;
    if(i==0) return res = (x==0);
    return res = f(x, i-1) + f(x-coins[i-1], i-1);
}

int main () {
    int sum, n;
    cin >> sum >> n;
    coins = vi(n);
    for(int& x : coins) cin >> x;
    c = vvll(sum+1, vll(n+1, -1));
}