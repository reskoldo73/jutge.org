#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n;
vi v;

void swap(int i, int j, vi& ans) {
    int aux = ans[j];
    ans[j] = ans[i];
    ans[i] = aux;
}

//cost = O(n²)
/*
Comparations:
    WCS: (n-1)(n-2)/2 = O(n²)
    BCS: n-1 = O(n)
Swaps:
    WCS: O(n²);
    BCS: 0

Better than selection overall, but not ideal with hard to swap elements
*/
void ins_sort() {
    vi ans;
    for(int i = 0; i < n; ++i) {
        ans.push_back(v[i]);
        int j = i;
        while(j > 0 and ans[j] < ans[j-1]) {
            swap(j, j - 1, ans);
            --j;
        }
    }
    v = ans;
}

int main () {
    cin >> n;
    v = vi(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    ins_sort();
    for(int x : v) cout << " " << x;
    cout << "\n";
}