/*
Write a program that, given a natural number s and n natural numbers x1, …, xn, prints all the subsets (maybe with repeated numbers, but using every xi at most once) whose sum is exactly s.

Input

Input consists of a natural number s, followed by a number n > 0, followed by x1, …, xn.

Output

Print all the subsets whose sum is s that can be made up with x1, …, xn.

Information about the checker
You can print in any order both the solutions and the elements inside each solution.

Hint

For this exercise, a very simple algorithm can be too slow.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int s, n, sum, maxsum;
vi v, inp;

void print() {
    cout << '{';
    for(int i = 0; i < (int)v.size(); ++i) cout << (i ? "," : "") << v[i];
    cout << "}\n";
}

void solve(int pos) {
    if(pos == n and sum == s) return print();
    if(pos == n or sum > s or sum + maxsum < s) return;

    int temp = inp[pos];
    maxsum -= temp;

    int tempmax = maxsum;

    v.push_back(temp);
    sum += temp;
    solve(pos+1);
    maxsum = tempmax;
    sum -= temp;
    v.pop_back();
    solve(pos+1);
    maxsum = tempmax;
}

int main () {
    cin >> s >> n;
    inp = vi(n);
    maxsum = 0;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        inp[i] = temp;
        maxsum += temp;
    } 
    v = vi();
    sum = 0;
    solve(0);
}