/*
Consider a rectangular board r × c with r ≤ c. Write a program that prints all the ways to place r rooks on the board so that no rook threatens another rook.

Input

Input consists of two natural numbers r and c, with 1 ≤ r ≤ c.

Output

Print all the ways to place r rooks on the board so that no rook threatens another rook. Represent the rooks with a ‘R’, and the empty positions with a dot. Print an empty line after each board.

Information about the checker
You can print the solutions to this exercise in any order.
*/
#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

vi board;
vb avail;
int r, c;

void print() {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cout << ((board[i] == j) ? "R" : ".");
        }
        cout << "\n";
    }
    cout << "\n";
}

void solve(int pos) {
    if(pos == r) return print();
    for(int i = 0; i < c; ++i) {
        if(avail[i]) {
            board[pos] = i;
            avail[i] = false;
            solve(pos+1);
            avail[i] = true;         
        }
    }  
}

int main () {
    cin >> r >> c;
    avail = vb(c, true);
    board = vi(c);
    solve(0);
}

