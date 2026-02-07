// The Cube
// https://jutge.org/problems/P66524_en
// P66524_en:std:none:
// Created on 7/29/2025, 11:52:23 AM by Luis de Carlos García

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<long long> X(n), Y(n), Z(n);
        for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i] >> Z[i];
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        sort(Z.begin(), Z.end());
        long long mx = X[n/2], my = Y[n/2], mz = Z[n/2];
        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += abs(X[i] - mx) + abs(Y[i] - my) + abs(Z[i] - mz);
        cout << sum << endl;
    }
}
