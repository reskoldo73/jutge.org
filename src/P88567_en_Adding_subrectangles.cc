/*
Given a grid with uppercase letters, compute the sum of the values of the
letters in each rectangle with a corner in the upper-left extreme. The values of
the letters are ’A’=1, ’B’=1+2=3, ’C’=1+2+3=6, ’D’=1+2+3+4=10, etcetera, up to
’Z’=351.

Input

Input consists of 0< r≤ 500 lines, all of them with the same number of uppercase
letters 0<c≤ 500.

Output

Print r lines with c numbers each. The j-th number of the i-th row must be the
sum of the values of the letters of the rectangle whose corners are the first
letter of the input, and the j-th letter of the i-th row.

Hint

Consider using the inclusion-exclusion principle.
*/

//reskoldo73, 2025-09-28

#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vi = vector<int>;

//ugly code, should consider dividing the main.

const int alphabetsize = (int)('Z' - 'A' + 1);

ll chartoll(char c) {
    if('A' <= c && c <= 'Z') return (ll)(c-'A'+1);
    else return 0;
}

int main () {
    vi nums(alphabetsize + 1, 0);
    for(int i = 1; i <= alphabetsize; ++i) nums[i] = nums[i-1] + i;
    vvll ans;
    int i = 0;
    string in;
    int insize = 0;
    while(cin >> in) {
        insize = in.size();
        vll aux(insize, 0);
        for(int j = 0; j < (int)in.size(); ++j) {
            aux[j] += nums[chartoll(in[j])];
            bool i0 = i > 0;
            bool j0 = j > 0;
            if(i0) aux[j] += ans[i-1][j];
            if(j0) aux[j] += aux[j-1];
            if(i0 and j0) aux[j] -= ans[i-1][j-1];
        }
        ans.push_back(aux);
        ++i;
    }
    for(i = 0; i < (int)ans.size(); ++i) {
        for(int j = 0; j < insize; ++j) {
            cout << (j ? " " : "") << ans[i][j];
        }
        cout << "\n";
    }
}