/*
Find all the paths that a tortoise can travel from an initial position to a final position. The ground has n × m paving stones, each one with a letter painted on it. The tortoise can only make horizontal and vertical movements, and it cannot pass by the same position twice.

Input

Input begins with n and m, followed by n lines with m letters each. Follow a pair of natural numbers indicating the initial row and column, and a pair of naturals numbers indicating the final row and column. The upper-left corner corresponds to the position (0, 0).

Output

Print all the paths from the initial position to the final position.

Information about the checker
You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int,int>;

int n, m;
vvc let;
vvb avail;
vc ans;
pii a, b;

void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void print() {
    for(char x : ans) cout << x;
    cout << "\n";
}

void solve();

void auxsolve() {
    if(avail[a.first][a.second]) {
        avail[a.first][a.second] = false;
        ans.push_back(let[a.first][a.second]);
        solve();
        ans.pop_back();
        avail[a.first][a.second] = true;
    }
}

void solve() {
    if(a == b) return print();

    ++a.first;
    if(a.first < n) auxsolve();
    --a.first;
    --a.first;
    if(a.first >= 0) auxsolve();
    ++a.first;

    ++a.second;
    if(a.second < m) auxsolve();
    --a.second;
    --a.second;
    if(a.second >= 0) auxsolve();
    ++a.second;
}

int main () {
    cin >> n >> m;
    let = vvc(n, vc(m));
    avail = vvb(n, vb(m, true));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cin >> let[i][j];
    }
    ans = vc();
    cin >> a.first >> a.second >> b.first >> b.second;
    ans.push_back(let[a.first][a.second]);
    avail[a.first][a.second] = false;
    solve();
}