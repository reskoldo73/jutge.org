/*
Write a program that prints the number of sequences made up of exactly z zeros
and u ones that do not contain two consecutive zeros nor three consecutive ones.

For instance, there are 8 sequences for z = 3 and u = 4:

0101011   0101101   0110101   0110110   1010101   1010110   1011010   1101010
Input

Input consists of several pairs of natural numbers z and u, each between 0 and
90.

Output

For every pair of z and u, print the required number.
*/

//reskoldo73, 2025-10-09

#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

//wrong approach

const int maxz = 90;
const int maxu = 90;

vvll memo01;
vvll memo10;
vvll memo11;

ll solve01(int z, int u);
ll solve10(int z, int u);
ll solve11(int z, int u);

ll solve01(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo01[z][u] != -1) return memo01[z][u];
    return memo01[z][u] = solve10(z, u-1);
}

ll solve10(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo10[z][u] != -1) return memo10[z][u];
    return memo10[z][u] = solve01(z-1, u) + solve11(z-1, u);
}


ll solve11(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo11[z][u] != -1) return memo11[z][u];
    return memo11[z][u] = solve01(z, u-1);
}

int main() {
    memo01 = vvll(maxz+1, vll(maxu+1, -1));
    memo10 = vvll(maxz+1, vll(maxu+1, -1));
    memo11 = vvll(maxz+1, vll(maxu+1, -1));
    memo01[0][1] = memo01[1][1] = memo10[1][1] = memo10[1][0] = memo11[0][2] = 1;

    int z, u;
    while(cin >> z >> u) {
        if(z == 0 and u == 0) cout << 1 << "\n";
        else cout << solve01(z, u) + solve10(z, u) + solve11(z, u) << "\n";
    }

}