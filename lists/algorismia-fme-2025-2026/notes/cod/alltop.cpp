// https://jutge.org/problems/P16249_en
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

using Graph = vector<vector<int>>;

template<typename T>
void print(const vector<T>& v) {
    bool first = true;
    for (const T& w: v) {
        if (!first) cout << " ";
        cout << w;
        first = false;
    }
    cout << endl;
}

void bt(set<int>& q, const Graph& G, vector<int>& grau, vector<int>& ret) {
    if (ret.size() == G.size()) print(ret);
    else if (!q.empty()) {
        vector<int> choices(q.begin(), q.end()); 
        for (int x : choices) {
            q.erase(x);
            ret.push_back(x);

            vector<int> added;
            for (int y : G[x])
                if (--grau[y] == 0) { q.insert(y); added.push_back(y); }
            bt(q, G, grau, ret);
            for (int y : G[x]) ++grau[y];
            for (int y : added) q.erase(y);

            ret.pop_back();
            q.insert(x);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph G(n);
    vector<int> grau(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        ++grau[y];
    }

    vector<int> ret;
    set<int> q;
    for (int x = 0; x < n; ++x)
        if (grau[x] == 0) q.insert(x);
    bt(q, G, grau, ret);
}
