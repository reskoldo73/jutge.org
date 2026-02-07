/*
Write a program that prints all the ways to place k kings on a n × n board so
that no king threatens another king. Remember that a king threatens all the
surrounding cells, either horizontally, vertically, or diagonally.

Input

Input consists of two natural numbers n > 0 and 0 ≤ k ≤ n2.

Output

Print all the ways to place k kings on a n × n board so that no king threatens
another king. Mark the kings with a ‘K’, and the empty cells with a dot. Print a
line with ten hyphens after every board.

Information about the checker You can print the solutions to this exercise in
any order.

Observation

The test cases of this problem do not require a very clever algorithm.
*/

//reskoldo73, 2025-09-19

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

//dif 1.3 ccn 1.1 ratios

int n, k, count;
vvi board;

void print() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) cout << (board[i][j] == -1 ? 'K' : '.');
        cout << "\n";
    }
    cout << "----------\n";
}

void fix(int x, int y, int val) {
    bool up = x-1 >= 0;
    bool down = x+1 < n;
    bool left = y-1 >= 0;
    bool right = y+1 < n;
    if(up) {
        if(right) board[x-1][y+1] += val;
        if(left) board[x-1][y-1] += val;
        board[x-1][y] += val;    }
    if(down) {
        if(right) board[x+1][y+1] += val;
        if(left) board[x+1][y-1] += val;
        board[x+1][y] += val;
    }
    if(right) board[x][y+1] += val;
    if(left) board[x][y-1]+=val;

    board[x][y] -= val;
}

void solve(int pos) {
    if(pos == n*n){
        if(count == k) print();
        return;
    }
    if(n*n - pos < k - count or count > k) return;

    int x = pos/n;
    int y = pos%n;
    if(board[x][y] == 0) {
        fix(x, y, 1);
        ++count;
        solve(pos+1);
        --count;
        fix(x, y, -1);
    }
    solve(pos+1);

}

int main() {
    cin >> n >> k;
    board = vvi(n, vi(n, 0));
    count = 0;
    solve(0);
}