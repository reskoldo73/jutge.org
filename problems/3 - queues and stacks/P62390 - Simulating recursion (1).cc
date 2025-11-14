/*
In C++, consider this program (whose inclusions have been removed):

    void work(int n) {
        if (n > 0) {
            cout << ' ' << n;
            work(n - 1);
            work(n - 1);
        }
    }

    int main() {
        int n;
        while (cin >> n) {
            work(n);
            cout << endl;
        }
    }
Take a look at the sample input and sample output to see what this program prints for every given number.

Without modifying @main()@, reimplement the procedure @work(n)@ with no calls at all, recursive or not, so that the output of the program does not change.

Input

Input consists of several strictly positive natural numbers.

Output

For every number, print a line identical to the one written by the program above.

Observation

To solve this exercise, the only containers that you should use are stacks.
*/

#include <iostream>
#include <stack>

using namespace std;

void work(int n) {
    stack<int> ans;
    ans.push(n);
    while(not ans.empty()) {
        int temp = ans.top(); ans.pop();
        if(temp > 0) {
            cout << ' ' << temp--;
            ans.push(temp);
            ans.push(temp);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        work(n);
        cout << endl;
    }
}