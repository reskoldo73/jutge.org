/*
Write a program to solve Sudoku puzzles. Your program will be tested against Sudokus that have appeared in some newspapers. These are guaranteed to have a unique solution.

Input

Input begins with a line with a number n ≥ 1. Follow n Sudokus, each one consisting of nine lines, each one with nine space-separated characters, which are digits from 1 to 9 and dots. The latter indicate cells that are still empty. There is a blank line before every puzzle.

Output

Print the solutions using the same format as in the input: First, print n on a line. For each puzzle, print nine lines, each with nine digits separated by spaces. Print a blank line before every solution.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using mat = vector<vi>;
using line = vector<vb>;
using square = vector<line>;

int n;
mat board;
square mini;
line rows, cols;
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
    board = mat(9, vi(9, 0));
    mini = square(3, line(3, vb(10, true)));
    rows = cols = line(9, vb(10, true));
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