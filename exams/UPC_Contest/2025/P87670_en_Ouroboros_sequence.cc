// Ouroboros sequence
// https://jutge.org/problems/P87670_en
// P87670_en:std:none:
// Created on 7/29/2025, 12:05:02 PM by Luis de Carlos García

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool pot(map <int, int>& count, int n, int mn, int mx, vector<int>& V) {
    if(n%2 == 1) return false;
    int temp = mx;
    int i = n;
    while(temp > mn) {
        if(count[--temp]--) V[--i] = temp;
        else return false;
    }
    auto it = count.end();
    --it;
    --it;
    count[mn - 1] = 0;
    count[mx + 1] = 0;
    i = 1;
    bool fw = false;
    while(it->second != 0) {
        V[i++] = it->first;
        --(it->second);
        if(fw) {
            ++it;
            if(it == count.end() or it->second == 0) {
                fw = false;
                it--;
                --it;
            }
        } else {
            --it;
            if(it == count.begin() or it->second == 0) {
                fw = true;
                it++;
                ++it;
            }
        }
    }
    for(it = count.begin(); it != count.end(); ++it) {
        if(it->second != 0) return false;
    }
    return V[n - (mx - mn) - 1] == mn + 1;
}

int main() {
    int n;
    while (cin >> n) {
        map<int, int> count;
        int mn = 1001, mx = 0;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            ++count[temp];
            mn = min(mn, temp);
            mx = max(mx, temp);
        }
        vector<int> V(n, -2);
        V[0] = mx;
        --count[mx];
        if(pot(count, n, mn, mx, V)) {
            cout << "YES";
            for(int i = 0; i < n; ++i) cout << ' ' << V[i];
            cout << "\n";
        }
        else cout << "NO\n";
    }
}
