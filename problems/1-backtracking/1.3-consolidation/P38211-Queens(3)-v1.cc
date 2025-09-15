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

mat board;
int n, count;
vi queens;
bool solved;

//time limit exceeded

void print() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << (queens[i] == j ? "Q" : ".");
        }
        cout << "\n";
    }
}

void fill(int x, int y, int z) {
    for(int i = 0; i < n; ++i) {
        board[i][y] += z;
        board[x][i] += z;
    }
    for(int k = 1; k < n; ++k) {
        bool up, down, left, right;
        up = x-k >= 0;
        down = x+k < n;
        left = y-k >= 0;
        right = y+k < n;
        if(not(up or down or left or right)) return;
        if(up and left) board[x-k][y-k] += z;
        if(up and right) board[x-k][y+k] += z;
        if(down and left) board[x+k][y-k] += z;
        if(down and right) board[x+k][y+k] += z;
    }

}

void solve(int pos) {
    if(solved) return;
    if(pos == n) {
        print();
        solved = true;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(board[pos][i] == 0) {
            queens[pos] = i;
            fill(pos, i, 1);
            solve(pos+1);
            fill(pos, i, -1);
        }
    }
    
}

int main () {
    cin >> n;
    count = 0;
    board = mat(n, vi(n, 0));
    queens = vi(n);
    solved = false;
    solve(0);
    if(not solved) cout << "NO SOLUTION\n";
}