/*
Consider n different species. Some may be incompatible, in the sense that they must be kept separated. For example, if the species were human, lion, gorilla, buffalo and antelope, then the list of incompatibilities might be: we cannot put a human next to a lion, nor a human next to a buffalo, nor a lion next to a buffalo, nor a lion next to a antelope.

Write a program that reads the incompatibilities between species, and writes all the ways to put in a row an individual of every species, so that two incompatible species are never one beside the other.

Input

Input begins with a number n between 1 and 52, followed by n letters, each identifying a different species. Then comes a number m, followed by m different pairs of letters, each indicating an incompatibility between two of the n given species.

The first sample input corresponds to the example given above. “HL” means that we cannot put a human next to a lion, etc. Note that “LH” would mean exactly the same.

Output

Print all the ways of placing n individuals in a row, one of each species, so that incompatible species are not together.

Information about the checker
You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;

vc all(52);

vi spe;

vi perm;
vb avail;
vector<vb> inc(52, vb(52, true));

int n;

int chartoint(char c) {
    if('A' <= c and c <= 'Z') return (int)(c-'A');
    else if ('a' <= c and c <= 'z') return (int)(c-'a' + 26);
    else return -1;
}

void print() {
    for(int i = 0; i < n; ++i) cout << all[perm[i]];
    cout << "\n";
}

void solve(int pos) {
    if(pos == n) return print();
    for(int i = 0; i < n; ++i) {
        if(avail[i] and (pos == 0 or inc[perm[pos-1]][spe[i]])) {
            avail[i] = false;
            perm[pos] = spe[i];
            solve(pos+1);
            avail[i] = true;
        }
    }
}

int main () {
    for(int i = 0; i < 26; ++i) {
        all[i] = (char)('A' + i);
        all[i+26] = (char)('a' + i);
    }
    cin >> n;
    spe = vi(n);
    for(int i = 0; i < n; ++i) {
        char temp;
        cin >> temp;
        spe[i] = chartoint(temp);
    }
    avail = vb(n, true);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        string temp;
        cin >> temp;
        int x, y;
        x = chartoint(temp[0]);
        y = chartoint(temp[1]);
        inc[x][y] = inc[y][x] = false;
    }
    perm = vi(n);
    solve(0);
}