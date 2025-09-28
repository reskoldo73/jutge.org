/*
The Milabs are the inhabitants of the Milab planet. Those bugs have a highly developed brain. By contrast, its prehistoric vocal cords are very limited, something which forced them to develop the odd Nuxaeron language.

The Nuxaeron alphabet is binary. However, instead of writing ones and zeros (as any good programmer would do), they write parentheses. In principle, 2k words of length k can be made up, since each character can be ‘(’ (pronounced “uhng”) or ‘)’ (pronounced “uhhhn”). But even if they are so smart, the Milabs are as lazy as the inhabitants of the Earth (or “()()(()(()))”, as they call it) so they do not want to memorize too many different words. Therefore, they have set a rule: they can only say well parenthesized words, i.e., they may say “()” or “(()())”, but can not say “())(” or “)(”. For example, these are the right 5 words of length 6:

((()))   ()(())   (())()   (()())   ()()()
To speak Nuxaeron correctly, you will have to determine how many correct words of length n exist.

Input

Input consists of several natural numbers n between 1 and 67.

Output

For every n, print the number of Nuxaeron correct words of that size.

Observation

If you do not know what are the Catalan numbers, this is a good time to learn it.
*/

#include <iostream>
#include <vector>
using namespace std;

const int sizev = 33;

using ll = long long;
using vll = vector<ll>;

int n;
vll cat;

ll solve(int x) {
    if(x%2 == 1) return 0;
    x/=2;
    if(cat[x] == -1) {
        return cat[x] = solve(2*(x-1))*2*(2*x-1)/(x+1);
    }
    return cat[x];
}

int main () {
    cat = vll(sizev + 1, -1);
    cat[0] = 1;
    while(cin >> n) cout << solve(n) << "\n";
}