#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        long long cost[n][3];
        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < n; ++i)
                cin >> cost[i][j];
        // dp[c] = coste mínimo para pintar todas las casas posteriores si pinto la actual de color c
        vector<long long> dp(3);            
        for (int i = n - 1; i >= 0; --i) {
            vector<long long> next(3);      // dp[] para la siguiente iteración
            for (int j = 0; j < 3; ++j)
                next[j] = cost[i][j] + min(dp[(j + 1) % 3], dp[(j + 2) % 3]);
            dp.swap(next);
        }
        cout << *min_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}
