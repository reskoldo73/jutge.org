/*
Write a program to find all the possible solutions of a Sudoku.

Input

Input begins with a number n, followed by n Sudokus. Every Sudoku consists of 81 numbers between zero and nine, plus the characters shown in the examples. A zero indicates an unknown value. Except for zeros, there are no repeated numbers in any row, nor in any column, nor in any of the nine 3 × 3 squares.

Output

For every Sudoku, print all the possible solutions in lexicographical order, each one followed by an empty line. Print “no solution” if there is no solution. Print a line with 30 asterisks after the output for every Sudoku.

Observation

The data tests are chosen so that a backtracking program that simply fills the rows from top to bottom and from left to right will be fast enough.
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
    for(int i = 0; i < 9; ++i) {
        if(i == 3 or i == 6) cout << "------+-------+------\n";
        for(int j = 0; j < 9; ++j) {
            if(j == 3 or j == 6) cout << " |";
            cout << (j ? " " : "") << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(int pos) {
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
        if(i == 3 or i == 6) {
            string trash;
            cin >> trash;
        }        
        for(int j = 0; j < 9; ++j) {
            char aux;
            if(j == 3 or j == 6) cin >> aux;

            cin >> aux;
            int temp = chartoint(aux);
            board[i][j] = temp;
            if(temp != 0) fix(i, j, temp, false);
        }
    }
    solved = false;
    solve(0);
    if(not solved) cout << "no solution\n";
    for(int i = 0; i < 30; ++i) cout << '*';
    cout << "\n";
}

int main () {
    cin >> n;
    while(n--) read();
}