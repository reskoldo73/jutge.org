/*
Write a program to find the unique solution of a Sudoku.

Input

Input begins with a number n, followed by n Sudokus. Every Sudoku consists of 81
numbers between zero and nine, plus the characters shown in the examples. A zero
indicates an unknown value. Except for zeros, there are no repeated numbers in
any row, nor in any column, nor in any of the nine squares 3 × 3. Every Sudoku
has exactly one solution.

Output

For every Sudoku, print its unique solution, followed by an empty line.

Observation

A backtracking program that simply fills the rows from top to bottom and from
left to right should not be fast enough to solve this exercise. Instead, at
every step of the backtracking, fill the empty cell (or one of the empty cells)
with less options left.
*/

//reskoldo73, 2025-09-21

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using pii = pair<int,int>;

int n;
pii p;
vvi board;
vvb rows, cols, mini;
bool solved;

int chartoint(char c) {
    if('0' <= c and c <= '9') return (int)(c - '0');
    return 0;
}

bool check(int x, int y, int z) {
    return rows[x][z] and cols[y][z] and mini[(x/3)*3 + y/3][z];
}

void fix(int x, int y, int z, bool b) {
    rows[x][z] = b;
    cols[y][z] = b;
    mini[(x/3)*3 + y/3][z] = b;
    board[x][y] = b ? 0 : z;
}

void print() {
    for(int i = 0; i < 9; ++i) {
        if(i == 3 || i == 6) cout << "------+-------+------\n";
        for(int j = 0; j < 9; ++j) {
            if(j == 3 || j == 6) cout << " |";
            cout << (j ? " " : "") << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

pii find_min_options() {
    pii best = {-1, -1};
    int min_options = 10;
    
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == 0) {
                int count = 0;
                for(int num = 1; num < 10; ++num) {
                    if(check(i, j, num)) ++count;
                }
                if(count < min_options) {
                    min_options = count;
                    best = {i, j};
                }
                if(min_options == 1) break;
            }
        }
        if(min_options == 1) break;
    }
    
    return best;
}

bool is_solved() {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == 0) return false;
        }
    }
    return true;
}

void solve() {
    if(is_solved()) {
        solved = true;
        return;
    }
    
    pii cell = find_min_options();
    if(cell.first == -1) return; // No empty cells found
    
    int x = cell.first, y = cell.second;
    
    for(int num = 1; num <= 9; ++num) {
        if(check(x, y, num)) {
            fix(x, y, num, false);
            solve();
            if(solved) return;
            fix(x, y, num, true);
        }
    }
}

void read() {
    board = vvi(9, vi(9, 0));
    rows = vvb(9, vb(10, true));
    cols = vvb(9, vb(10, true));
    mini = vvb(9, vb(10, true));
    
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
            if(temp != 0) {
                board[i][j] = temp;
                fix(i, j, temp, false);
            }
        }
    }
    solved = false;
    solve();
    print();
}

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fast_io();
    cin >> n;
    while(n--) read();
}