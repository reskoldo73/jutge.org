/*
Write a program to compute the number of different paths that allow us to scape from a given maze, by going from the bottom-right cell to the upper-left cell. Every movement must be upwards or to the left. There are prohibited cells that we cannot pass by. There is always at least one path from the entrance to the exit.

Input

Input consists of several cases. Every case begins with the number of rows n and the number of columns m, followed by n lines with m characters each. An ‘X’ indicates a forbidden cell, and a dot indicates a free cell. A special test with n = m = 0 marks the end of input. You can assume 2 ≤ n ≤ 40 and 2 ≤ m ≤ 40.

Output

For every case, print the number of different paths that go from the bottom-right corner to the upper-left corner, with all the movements upwards or to the left. If this number is greater than or equal to 106, instead print “!!!”.

Hint

The fact that some cell has too many paths from the entrance (or to the exit) does not imply for sure that there are too many paths from the entrance to the exit.
*/

#include <iostream>
#include <vector>

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;

const int maxans = 1e6;

vvi memo;
vvb maze;
bool pass;
int ans;

int solve(int i, int j) {
    if(ans >= maxans) pass = true;
    if(pass or i < 0 or j < 0 or maze[i][j]) return 0;
    if(memo[i][j] != -1) {
        ans = memo[i][j];
        if(ans>=maxans) pass = true;
        return ans;
    }
    memo[i][j] = solve(i-1, j) + solve(i, j-1);
    ans = memo[i][j];
    if(ans>=maxans) pass = true;
    return memo[i][j];
}

int main () {
    int n, m;
    while(cin >> n >> m and (m != 0 or n != 0)) {
        maze = vvb(n, vb(m, false));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char temp;
                cin >> temp;
                maze[i][j] = temp == 'X';
            }
        }
        pass = false;
        ans = 0;
        memo = vvi(n, vi(m, -1));
        memo[0][0] = 1;
        ans = solve(n-1, m-1);
        if(pass) cout << "!!!\n";
        else cout << ans << "\n";

    }
}