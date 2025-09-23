/*
Input
Input consists of several cases, each with two natural numbers n and k, where 0 ≤ n ≤ 30
and 0 ≤ k ≤ n.
Output
For each case, print (
n
k
).
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

const int matsize = 31;

vii mat;

int f(int n, int k) {
    if(mat[n][k] != -1) return mat[n][k];
    return mat[n][k] = f(n-1, k-1) + f(n-1, k);
}

int main () {
    mat = vii(matsize, vi(matsize, -1));
    for(int i = 0; i < matsize; ++i) {
        mat[i][0] = 1;
        mat[i][i] = 1;
    }
    int n, k;
    while(cin >> n >> k) cout << f(n, k) << endl;
}