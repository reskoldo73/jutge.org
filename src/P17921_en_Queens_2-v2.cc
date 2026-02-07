/*
Write a program to print all the ways to place n queens on an n × n chessboard
so that no queen threatens another queen.

Input

Input consists of a natural number n > 0.

Output

Print all the ways to put n queens on an n × n chessboard so that no queen
threatens another queen. The queens must be marked with a ‘Q’, and the empty
positions with a dot. Print an empty line after each board.

Information about the checker You can print the solutions to this exercise in
any order.
*/

//reskoldo73, 2025-09-15

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

using mat = vector<vi>;

int n, count;
vi queens;
vb diag1, diag2, cols;

void print() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << (queens[i] == j ? "Q" : ".");
        }
        cout << "\n";
    }
    cout << "\n";
}


void solve(int pos) {
    if(pos == n) return print();
    for(int i = 0; i < n; ++i) {
        if(cols[i]) {
            int d1 = pos + i;
            int d2 = pos - i + n - 1;
            if(diag1[d1] and diag2[d2]) {
                cols[i] = diag1[d1] = diag2[d2] = false;
                queens[pos] = i;
                solve(pos+1);
                cols[i] = diag1[d1] = diag2[d2] = true;
            }
        }
    }
}

int main () {
    cin >> n;
    count = 0;
    queens = vi(n);
    diag1 = diag2 = vb(2*n-1, true);
    cols = vb(n, true);
    solve(0);
}