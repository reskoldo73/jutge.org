/*
Jaher is a brilliant algorithmist, but he is also a bit absent minded. For example, he has some difficulties making things fit into his suitcase. Can you help him?

For simplicity, let us assume a two-dimensional suitcase a × b, where n ‍rectangular objects must fit. Objects can be placed at any position within the suitcase, without overlap, but they can not be rotated. In how many ways can we put the objects?

Input

Input consists of several cases. Each case begins with a, b and n. Follow n pairs of strictly positive natural numbers, which indicate the sizes of the objects. The area of the objects exactly covers the suitcase, and there is always at least one possible solution. (The first case in the sample input corresponds to the picture.)

Output

For every suitcase, print a line with its number and how many possible solutions exist.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vpii = vector<pii>;

int a, b, n, count, rem;
vvb suit;
vb avail;
vpii stuff;

bool ok(int pos, pii p) {
    int x = p.first;
    int y = p.second;
    int xx = pos/b;
    int yy = pos%b;
    if(xx + x > a or yy + y > b) return false;
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            if(not suit[xx + i][yy + j]) return false;
        } 
    }
    return true;
}

void fix(int pos, pii p, bool val) {
    int x = p.first;
    int y = p.second;
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            suit[pos/b + i][pos%b + j] = val;
        } 
    }
}

void solve(int pos) {
    if(rem == 0) {
        ++count;
        return;
    } 
    if(pos == a*b) return;
    int x = pos/b;
    int y = pos%b;

    if(suit[x][y]) {
        for(int i = 0; i < n; ++i) {
            if(avail[i]) {
                pii p = stuff[i];
                if(ok(pos, p)) {
                    avail[i] = false;
                    fix(pos, p, false);
                    --rem;
                    solve(pos+1);
                    ++rem;
                    fix(pos, p, true);
                    avail[i] = true;
                }                
            }
        }
    }
    else solve(pos+1);

}

int main () {
    int it = 0;
    while(cin >> a >> b >> n) {
        stuff = vpii(n);
        for(int i = 0; i < n; ++i) cin >> stuff[i].first >> stuff[i].second;
        suit = vvb(a, vb(b, true));
        avail = vb(n, true);
        rem = n;
        count = 0;
        solve(0);
        cout << "#" << ++it << ": " << count << "\n";
    }
}