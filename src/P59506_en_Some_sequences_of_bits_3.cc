/*
Write a program that prints the number of sequences made up of exactly z zeros
and u ones that are multiple of three when considered as a binary number. Note
that numbers that begin with one or more zeros are allowed here.

For instance, there are 9 sequences for z = 2 and u = 4:

001111   011011   011110   100111   101101   110011   110110   111001   111100
Input

Input consists of several pairs of natural numbers z and u, each between 0 and
30.

Output

For every pair of z and u, print the required number.
*/

//reskoldo73, 2025-10-10

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;


const int maxz = 30;
const int maxu = 30;
vvll memo0;
vvll memo1;
vvll memo2;

ll solve0(int z, int u);
ll solve1(int z, int u);
ll solve2(int z, int u);

ll solve0(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo0[z][u] != -1) return memo0[z][u];
    return memo0[z][u] = solve0(z-1, u) + solve1(z, u-1);
}

ll solve1(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo1[z][u] != -1) return memo1[z][u];
    return memo1[z][u] = solve2(z-1, u) + solve0(z, u-1);
}

ll solve2(int z, int u) {
    if(z < 0 or u < 0) return 0;
    if(memo2[z][u] != -1) return memo2[z][u];
    return memo2[z][u] = solve1(z-1, u) + solve2(z, u-1);
}

int main() {
    memo0 = memo1 = memo2 = vvll(maxz+1, vll(maxu+1, -1));
    memo0[0][0] = memo0[1][0] = memo1[0][1] = 1;
    memo0[0][1] = memo1[1][0] = memo2[1][0] = memo2[0][1] = 0;
    int z, u;
    while(cin >> z >> u) {
        cout << solve0(z, u) << "\n";
    }
}