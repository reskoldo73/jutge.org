/*
Let us define sequences similar to those of Collatz with two parameters x and y.
Given a number n, the algorithm to get the next number is:

if n is even, we move to n/2 + x; otherwise, we move to 3n + y. The standard
Collatz sequence corresponds to x = 0 and y = 1.

Given x, y and a starting number n, compute the length of the cycle reached by
applying the above algorithm. For example, if x = 1, y = 5 and n = 8, then the
defined sequence is 8, ‍5, 20, 11, 38, 20, 11, 38, …⁠ ⁠so the cycle has length
3.

Since numbers can become very large, and we have no mathematical guarantee that
we will reach a cycle, we will stop if at some point the sequence reaches a
number greater than 10^8.

Input

Input consists of several cases, each with three natural numbers x, y and n.
Assume that both x and y do not exceed 1000, that y is odd (for the sequence to
have some interest), and that the initial n is not larger than 108.

Output

For every case, print the length of the cycle, or the first number that strictly
exceeds 108.

Observation

Take into account that the sequences usually reach fast a “short” cycle.
*/

//reskoldo73, 2025-11-25

#include <iostream>
#include <unordered_map>

using namespace std;

const int maxn = 1e8;

int main () {
    int x, y, n;
    while(cin >> x >> y >> n) {
        unordered_map<int, int> visited;
        int steps = 0;
        visited[n] = 0;
        bool found = false;

        while(not found) {
            if(n % 2 == 0) n = n/2 + x;
            else n = 3*n + y;
            
            ++steps;
            
            if(n > maxn) {
                cout << n << endl;
                found = true;
            }

            if(not found and visited.count(n)) {
                cout << steps - visited[n] << endl;
                found = true;
            }
            
            visited[n] = steps;
        }
    }
}