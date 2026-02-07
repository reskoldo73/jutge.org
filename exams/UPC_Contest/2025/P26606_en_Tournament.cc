// Tournament
// https://jutge.org/problems/P26606_en
// P26606_en:std:none:
// Created on 7/29/2025, 11:23:50 AM by Luis de Carlos García

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector <string> teams(n);
        for(int i = 0; i < n; ++i) cin >> teams[i];
        int m = n/2;
        for(int i = 0; i < n - 1; ++i) {
            if(i%2 == 0) cout << teams[0] << '-' << teams[n - 1];
            else cout << teams[n - 1] << '-' << teams[0];
            for(int j = 1; j < m; ++j) {
                cout << ' ' << teams[j] << '-' << teams[n - 1 - j];
            }
            cout << "\n";
            
            string last = teams.back();
            for(int j = n - 1; j > 1; --j) teams[j] = teams[j - 1];
            teams[1] = last;
        }
        cout << "**********\n";
    }
}
