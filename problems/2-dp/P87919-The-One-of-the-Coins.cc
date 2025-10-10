/*
Perhaps you have read that some problems are so classic that they barely need a statement. For this one, given a collection of n coins with different values and a target amount A, we ask you to indicate the way to add up to A by using coins of the largest possible values. In particular, a way is better than another one if the former uses more coins of the largest value; in the event of a tie, if it uses more coins of the second largest value, etc.

Input

Input consists of several cases. Each case begins with the number of coins n between 1 and ‍100, followed by n different integer numbers v1, …, vn, where 1≤ vi≤ 10000. Finally, we have an integer number 1≤ A≤ 100000.

Output

For every case, print in non-increasing order the necessary coins to get A, choosing the combination with coins of largest value in case of a tie. If there is no solution, print −1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

int n, A;
vi val;

int main () {
    while(cin >> n) {
        val = vi(n);
        for(int &x : val) cin >> x;
        cin >> A;
        sort(val.begin(), val.end());
        vi ans(A+1, -1);
        
        // Initialize amount 0 as reachable (use 0 as marker)
        ans[0] = 0;
        
        int maxcoin = 0;
        for(int i = val[0]; i <= A; ++i) {
            if(maxcoin < n && i == val[maxcoin]) {
                ans[i] = val[maxcoin];
                if(maxcoin < n-1) ++maxcoin;  // Fixed bounds check
            }
            else {
                for(int j = maxcoin; j >= 0; --j) {
                    if(i >= val[j] && ans[i - val[j]] != -1) {  // Check for any reachable
                        ans[i] = val[j];
                        j = -1;
                    }
                }
            }
        }

        if(ans[A] == -1) {
            cout << -1 << endl;
        }
        else {
            bool first = true;
            while(A > 0) {
                if(not first) cout << ' ';
                else first = false;
                cout << ans[A];
                A -= ans[A];
            }
            cout << endl;
        }
    }
}
