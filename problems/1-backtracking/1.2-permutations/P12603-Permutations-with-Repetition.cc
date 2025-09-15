/*
Write a program that, given n different words s1, …, sn, prints all the permutations with repetitions that can be made with the words.

Input

Input consists of a natural number n > 0, followed by s1, …, sn.

Output

Print all the permutations with repetitions that can be made with s1, …, sn.

Information about the checker
You can print the solutions to this exercise in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vs = vector<string>;

vi perm;
int n;

vs words;

void print() {
    cout << '(';
    for(int i = 0; i < n; ++i) cout << (i ? "," : "") << words[perm[i]];
    cout << ")\n";
}

void solve(int pos) {
    if(pos == n) return print();
    for(int i = 0; i < n; ++i) {
        perm[pos] = i;
        solve(pos+1);
    }
    
}

int main () {
    cin >> n;
    words = vs(n);
    for(int i = 0; i < n; ++i) cin >> words[i];
    perm = vi(n);
    solve(0);
}

