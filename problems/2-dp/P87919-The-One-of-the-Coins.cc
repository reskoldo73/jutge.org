#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<vector<int>> dp;
vector<bool> done;

vector<int> f(int A) {
    if (A == 0) return vector<int>(0);    // valid: empty combination
    if (A < 0) return vector<int>(1, -1); // invalid marker
    if (done[A]) return dp[A];

    done[A] = true;

    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (A >= v[i]) {
            vector<int> t = f(A - v[i]);

            // t == {-1} means impossible; anything else is valid (including empty)
            if (!(t.size() == 1 && t[0] == -1)) {
                // build result r = [v[i]] + t (without using insert)
                vector<int> r;
                r.push_back(v[i]);
                for (int j = 0; j < (int)t.size(); ++j) r.push_back(t[j]);
                dp[A] = r;
                return dp[A]; // first valid found -> lexicographically best
            }
        }
    }

    dp[A] = vector<int>(1, -1);
    return dp[A];
}

int main() {
    int n;
    while (cin >> n) {
        v = vector<int>(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        int A;
        cin >> A;

        sort(v.rbegin(), v.rend()); // largest first

        dp = vector<vector<int>>(A + 1);
        done = vector<bool>(A + 1, false);

        vector<int> ans = f(A);

        if (ans.size() == 1 && ans[0] == -1) cout << -1 << "\n";
        else {
            for (int i = 0; i < (int)ans.size(); ++i) {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
