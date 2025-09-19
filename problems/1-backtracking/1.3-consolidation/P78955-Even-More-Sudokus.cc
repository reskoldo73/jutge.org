/*
Write a program to find the unique solution of a Sudoku.

Input

Input begins with a number n, followed by n Sudokus. Every Sudoku consists of 81 numbers between zero and nine, plus the characters shown in the examples. A zero indicates an unknown value. Except for zeros, there are no repeated numbers in any row, nor in any column, nor in any of the nine squares 3 × 3. Every Sudoku has exactly one solution.

Output

For every Sudoku, print its unique solution, followed by an empty line.

Observation

A backtracking program that simply fills the rows from top to bottom and from left to right should not be fast enough to solve this exercise. Instead, at every step of the backtracking, fill the empty cell (or one of the empty cells) with less options left.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;

//not solved, copy of sudokus

int n;
vvi board;
vvvb mini;
vvb rows, cols;
bool solved;

int chartoint(char c) {
    if('0' <= c and c <= '9') return (int)(c - '0');
    return 0;
}

bool check(int x, int y, int z) {
    return rows[x][z] and cols[y][z] and mini[x/3][y/3][z];
}

void fix(int x, int y, int z, bool b) {
    rows[x][z] = b;
    cols[y][z] = b;
    mini[x/3][y/3][z] = b;
}

void print() {
    cout << "\n";
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << (j ? " " : "") << board[i][j];
        }
        cout << "\n";
    }
}

void solve(int pos) {
    if (solved) return;
    if(pos == 81){
        solved = true;
        return print();
    }
    int x = pos/9;
    int y = pos%9;
    if(board[x][y] == 0){
        for(int i = 1; i < 10; ++i) {
            if(check(x, y, i)) {
                board[x][y] = i;
                fix(x, y, i, false);
                solve(pos+1);
                fix(x, y, i, true);
                board[x][y] = 0;
            }
        }
    }
    else solve(pos+1);
}

void read() {
    board = vvi(9, vi(9, 0));
    mini = vvvb(3, vvb(3, vb(10, true)));
    rows = cols = vvb(9, vb(10, true));
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            char aux;
            cin >> aux;
            int temp = chartoint(aux);
            board[i][j] = temp;
            if(temp != 0) fix(i, j, temp, false);
        }
    }
    solved = false;
    solve(0);
}

int main () {
    cin >> n;
    cout << n << "\n";
    while(n--) read();
}
