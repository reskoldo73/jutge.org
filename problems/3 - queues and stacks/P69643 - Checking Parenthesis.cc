/*
Write a program that checks the correct parenthesization of several given words by using a stack of characters.

Input

Input consists of several non-empty words made up only of ‘(’, ‘)’, ‘[’ and ‘]’.

Output

For every word, tell if it is correct or not, following the format of the example.
*/

//1.4 ccn ratio

#include <iostream>
#include <stack>

using namespace std;

int main () {
    string in;
    while(cin >> in) {
        int n = in.size();
        stack <char> s;
        bool ok = true;
        while (n-- and ok) {
            char temp = in[n];
            if(temp == ')' or temp == ']') s.push(temp);
            else {
                ok = false;
                if(not s.empty()) {
                    if(temp == '(') ok = ')' == s.top();
                    else ok = ']' == s.top(); //temp == '['
                    s.pop();
                } 
            }
        }
        ok = ok and s.empty();
        cout << in << " is " << (ok ? "correct\n" : "incorrect\n");
    }
}