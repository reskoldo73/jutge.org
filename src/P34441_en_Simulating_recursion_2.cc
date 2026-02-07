/*
Consider this program (whose inclusions have been removed):

    void print(int n) {
        if (n > 0) {
            print(n - 1);
            cout << ' ' << n;
            print(n - 1);
        }
    }

    int main() {
        int n;
        while (cin >> n) {
            print(n);
            cout << endl;
        }
    }
Take a look at the sample input and sample output to see what this program
prints for every given number.

Without modifying the @main()@, reimplement the procedure @print(n)@ with no
calls at all, recursive or not, so that the output of the program does not
change.

Input

Input consists of several strictly positive natural numbers.

Output

For every number, print a line identical to the one written by the program
above.

Observation

To solve this exercise, the only containers that you should use are stacks.
*/

//reskoldo73, 2025-11-13

#include <iostream>
#include <stack>

using namespace std;

void work(int n) {
    stack<int> ans;
    ans.push(n);
    while(not ans.empty()) {
        int temp = ans.top();
        if(temp == 1) {
            cout << " 1";
            ans.pop();
            if(not ans.empty()) {
                temp = ans.top();
                cout << ' ' << temp;
                ans.pop();
                ans.push(temp-1);
            }
        }
        else ans.push(temp-1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        work(n);
        cout << endl;
    }
}