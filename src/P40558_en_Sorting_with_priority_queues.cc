/*
Use priority queues to sort a sequence of integer numbers, in nondecreasing
order and also in nonincreasing order.

Input

Input consists of a sequence of integer numbers.

Output

Print two lines, the first one with the numbers in increasing order, and the
second one with the numbers in decreasing order.

Observation

To solve this exercise, the only containers that you should use are priority
queues of integer numbers.
*/

//reskoldo73, 2025-11-14

#include <iostream>
#include <queue>

using namespace std;

int main () {
    priority_queue<int> minheap;
    priority_queue<int> maxheap;

    int n;
    while(cin >> n) {
        minheap.push(-n);
        maxheap.push(n);
    }
    bool first = true;
    while(not minheap.empty()) {
        cout << (first ? "" : " ") << -minheap.top(); minheap.pop();
        first = false;
    }
    cout << endl;
    first = true;
    while(not maxheap.empty()) {
        cout << (first ? "" : " ") << maxheap.top(); maxheap.pop();
        first = false;
    }
    cout << endl;

}