/*
Write a program to print the lexicographically smallest way to place n queens on an n × n chessboard so that no queen threatens another queen.

Input

Input consists of a natural number n > 0.

Output

Mark the queens with a ‘Q’, and the empty positions with a dot. Print the lexicographically smallest way (by rows, from top to bottom, and assuming that a ‘Q’ is smaller than a dot) to place n queens on an n × n chessboard so that no queen threatens another queen. If there is no solution, print “NO SOLUTION”.
*/
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
}


bool solve(int pos) {
    if(pos == n) {
        print();
        return true;
    }
    for(int i = 0; i < n; ++i) {
        if(cols[i]) {
            int d1 = pos + i;
            int d2 = pos - i + n - 1;
            if(diag1[d1] and diag2[d2]) {
                cols[i] = diag1[d1] = diag2[d2] = false;
                queens[pos] = i;
                if(solve(pos+1)) return true;
                cols[i] = diag1[d1] = diag2[d2] = true;
            }
        }
    }
    return false;
}

int main () {
    cin >> n;
    count = 0;
    queens = vi(n);
    diag1 = diag2 = vb(2*n-1, true);
    cols = vb(n, true);
    if(not solve(0)) cout << "NO SOLUTION\n";
}