/*
Write a program that, given a natural number s and n natural numbers x1, …, xn,
prints all the subsets (maybe with repeated numbers, but using every xi at most
once) whose sum is exactly s.

Input

Input consists of a natural number s, followed by a number n > 0, followed by
x1, …, xn.

Output

Print all the subsets whose sum is s that can be made up with x1, …, xn.

Information about the checker You can print in any order both the solutions and
the elements inside each solution.

Hint

For this exercise, a very simple algorithm can be too slow.
*/

//reskoldo73, 2025-09-16

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;

int n, k, inv;
vb used;
vi v, sum;

void print() {
    cout << "(";
    for(int i = 0; i < n; ++i) {
        cout << (i ? "," : "") << v[i]+1;
    }
    cout << ")\n";
}

void solve(int pos) {
    if(pos == n) {
        if(inv == k) print();
        return;
    }
    if(inv > k or ((n-pos)*(n-pos-1)/2 + inv) < k) return;
    int c = 0;
    for(int i = 0; i < n; ++i) {
        if(not used[i]) {
            int temp = inv;
            inv += c; 
            used[i] = true; 
            v[pos] = i;
            solve(pos+1);
            used[i] = false;
            inv = temp;
            ++c;
        }
    }
}

int main() {
    cin >> n >> k;
    v = vi(n, 0);
    used = vb(n, false);
    inv = 0;
    solve(0);
}