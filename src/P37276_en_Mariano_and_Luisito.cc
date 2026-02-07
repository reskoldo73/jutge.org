/*
– Mariano, this level is very hard! –says Luisito.

– Come on, it is not that bad! –Mariano answers. We only have to traverse this
corridor of width W and length L. Here I have a complete map, see? We start at
the top, at the only cell with an ‘M’. Dots represent free cells, and asterisks
represent obtacles. The scroll makes us go down one cell every turn,
automatically and without pressing any key. Besides, if we press the “left” or
“right” keys, we go down diagonally, so to avoid obstacles until we reach the
bottom of the map.

– And those marks? Are they treasures?

– Let me see …no, a ‘T’ is for trap.

– I knew it! Mariano, let’s go home.

– Wait, the traps are not fatal. If we fall into one of them, we can scape by
pressing thrice the “up” key. Come on Luisitio, it is easy to discover the
optimal path!

Write a program that computes the minimum number of key-strokes necessary to
overcome the level.

Input

Input begins with the numbers 3 ≤ W ≤ 80 and 3 ≤ L ≤ 10000, followed by L lines
with W ‍characteres each, which represent the map. The first line contains
exactly one ‘M’. The rest of characters represent free cells ‘.’, obstacles ‘*’
or traps ‘T’.

Output

Print the minimum number of key-strokes needed to overcome the level. If it is
not possible, print “IMPOSSIBLE”.
*/

//reskoldo73, 2025-10-14

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

int w, l, ans;
vvi memo;
vvc grid;


//high ccn ratio = 2
int solve(int i, int j) {
    if(i >= l) return 0;
    if(j < 0 or j >= w or memo[i][j] == -2) return -2;
    if(memo[i][j] >= 0) return memo[i][j];
    if(grid[i][j] == '*') return memo[i][j] = -2;

    bool found = false;
    int min = -2;
    for(int k = -1; k < 2; ++k) {
        int temp = solve(i+1, j+k) + abs(k);
        if(temp >= 0) {
            if (grid[i][j] == 'T') temp += 3;
            if(not found) {
                min = temp;
                found = true;
            }
            else if (min > temp) min = temp;
        }
    }
    return memo[i][j] = min;
}

int main () {
    while(cin >> w >> l) {
        memo = vvi(l, vi(w, -1));
        grid = vvc(l, vc(w));
        int starti = 0, startj = 0;
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                if(i == 0 and grid[i][j] == 'M') {
                    starti = i;
                    startj = j;
                }
            }
        }
        int temp = solve(starti, startj);
        if(temp < 0) cout << "IMPOSSIBLE\n";
        else cout << temp << "\n";
        
    }
}