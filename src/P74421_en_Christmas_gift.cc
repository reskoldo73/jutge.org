/*
It is December 24th evening. An absent minded farmer has just realized that he
did not buy any gift for his wife. The farmer is on a path in the woods, and he
can only think about picking up all the mushrooms on the way back home, praying
that that will soften a bit the cries awaiting him. Suppose the path divided
into n segments 1, 2, …n, and that in each one there are a certain number of
mushrooms mi. The farmer is at the segment f, and his home is at the segment ‍h.
The farmer will pick up all the mushrooms in the segments between f and h. How
many mushrooms will it be?

Input

Input consists of several cases. Every case begins with n, followed by the n
quantities of mushrooms mi. Follow the number of queries q about this case,
assuming different positions of the farmer and his home. Each query consists of
f and h, both between 1 and n. Suppose 1 ≤ n ≤ 105, 0 ≤ mi ≤ 1000, and q > 0.

Output

For every case, print its number. For every query of every case, print the sum
of the numbers between f and h, the extrems inclusive.
*/

//reskoldo73, 2025-09-25

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n;
vi forest;


int solve(int a, int b) {
    if(b < a) {
        int aux = a;
        a = b;
        b = aux;
    }
    return forest[b] - forest[a-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int it = 0;
    while (cin >> n) {
        cout << '#' << ++it << "\n";
        forest = vi(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            forest[i] = forest[i-1] + m;
        }
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << solve(a, b) << "\n";
        }
    }
}



