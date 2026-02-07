/*
Write a program that prints all the permutations of { 1, …, n } with exactly one
cycle, for a given ‍n. Assume that the content of the position i of a
permutation indicates “the next position to visit”.

For instance, consider the permutation (4,3,2,5,1,7,6). The position 1 has a 4,
the position 4 has a 5, and the position 5 has a 1. Therefore, one of the cycles
of this permutation is 1 → 4 → 5 → 1. The other two cycles are 2 → 3 → 2 and 6 →
7 → 6. The permutation (3,2,1) has the two cycles 1 → 3 → 1 and 2 → 2. The
permutation (3,4,5,6,7,1,2) has only the cycle 1 → 3 → 5 → 7 → 2 → 4 → 6 → 1.

Input

Input consists of a natural number n > 0.

Output

Print all the permutations of { 1, …, n } with only one cycle.

Information about the checker You can print the solutions to this exercise in
any order.

Hint

The judge may accept a program that generates all the permutations and, for each
one, checks if it only has one cycle. However, this is not the right solution
for this problem.
*/

//reskoldo73, 2025-09-13 

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

int n;
vb avail;
vi v;

void print() {
    cout << "(";
    for(int i = 0; i < n; ++i) {
        cout << (i ? "," : "") << v[i]+1;
    }
    cout << ")\n";
}

void backtrack(int current, int count) {
    if (count == n) {
        v[current] = 0;
        print();
        return;
    }

    for (int i = 1; i < n; i++) {
        if (avail[i]) {
            avail[i] = false;
            v[current] = i;
            backtrack(i, count+1);
            avail[i] = true;
        }
    }
}

int main() {
    cin >> n;
    v = vi(n, 0);
    avail = vb(n, true);
    avail[0] = false;
    backtrack(0, 1);
}