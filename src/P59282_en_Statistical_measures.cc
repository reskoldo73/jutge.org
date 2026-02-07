/*
Write a program to compute the most common statistical measures (minimum,
maximum and average) of several integer numbers. These numbers are known
increasingly. At every moment, it is also possible to delete the smallest
element.

Input

Input consists of a sequence of (possibly, many) numbers, together with deleting
instructions, as can be seen in the sample input. The numbers may be repeated.
Deleting means removing the smallest element (one instance of it, if it is
repeated). If there are no elements, deleting does nothing.

Output

After every instruction of the input, print the minimum, maximum and average of
the current elements with four digits after the decimal point, or tell that
there are no elements. Follow the format of the sample output.
*/

//reskoldo73, 2025-11-14

#include <iostream>
#include <queue>

using namespace std;

using pqi = priority_queue<int>;

int main () {
    cout.setf(ios::fixed);
    cout.precision(4);

    int maxn = 0, sum = 0;
    pqi pq;

    string s;
    while(cin >> s) {
        if(s == "number") {
            int n;
            cin >> n;
            if(pq.empty()) maxn = sum = n;
            else {
                maxn = max(n, maxn);
                sum += n;
            }
            pq.push(-n);
            cout << "minimum: " << -pq.top() << ", maximum: " << maxn << ", average: " << sum / double(pq.size()) << endl;
        }
        else { //s == "delete"
            if(not pq.empty()) {
                int top = pq.top(); pq.pop();
                sum += top;
            } 
            if(pq.empty()) cout << "no elements" << endl;
            else cout << "minimum: " << -pq.top() << ", maximum: " << maxn << ", average: " << sum / double(pq.size()) << endl;
        }
    }
}