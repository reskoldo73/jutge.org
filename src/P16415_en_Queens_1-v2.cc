/*
Write a program to compute the number of ways to place n queens on an n × n
chessboard so that no queen threatens another queen. That is, no two queens can
be located on the same row, column or diagonal.

Input

Input consists of a natural number n > 0.

Output

Print the number of ways to put n queens on an n × n chessboard so that no queen
threatens another queen.
*/

//reskoldo73, 2025-09-15

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;

int n, count;
vb diag1, diag2, cols;

void solve(int pos) {
    if(pos == n) {
        ++count;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(cols[i]) {
            int d1 = pos + i;
            int d2 = pos - i + n - 1;
            if(diag1[d1] and diag2[d2]) {
                cols[i] = diag1[d1] = diag2[d2] = false;
                solve(pos+1);
                cols[i] = diag1[d1] = diag2[d2] = true;
            }
        }
    }
}

int main () {
    cin >> n;
    count = 0;
    diag1 = diag2 = vb(2*n-1, true);
    cols = vb(n, true);
    solve(0);
    cout << count << "\n";
}