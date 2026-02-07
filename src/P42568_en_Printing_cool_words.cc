/*
In this problem, we say that a word is cool if it does not have two consecutive
consonants. Write a program to print all the cool words with n lowercase
letters, v of which are vowels, that can be made up from the x first letters of
the alphabet.

For instance, these are some of the many cool words for n = 5, v = 3 and x = 5:

aabab ⁠ ⁠ababa ⁠ ⁠babaa ⁠ ⁠cecea ⁠ ⁠deeac

Input

Input consists of three natural numbers n > 0, 0 ≤ v ≤ n, and 2 ≤ x ≤ 26.

Output

Print, in alphabetic order, all the cool words with n lowercase letters, v of
which are vowels, that can be made up from the x first lowercase letters. Assume
that ‘y’ is a consonant.
*/

//2025-09-18

#include <iostream>
#include <vector>
using namespace std;

using vc = vector<char>;
using vi = vector<int>;
using vb = vector<bool>;

//1.1 Halstead diff and 1.2 ccn ratios

int n, v, x, count;
string ans;

inline bool is_vowel(char c) {
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

void solve(int pos, bool ok) {
    if(pos == n) {
        if(count == v)cout << ans << "\n";
        return;
    }
    int npos = n - pos;
    int vcount = v - count;
    if(count > v or 2*vcount + 1 < npos or npos < vcount) return;

    for(int i = 0; i < x; ++i) {
        char temp = (char)('a' + i);
        ans[pos] = temp;
        if(is_vowel(temp)) {
            ++count;
            solve(pos+1, true);
            --count;
        }
        else if (ok) {
            solve(pos+1, false);
        }
    }

}

int main() {
    cin >> n >> v >> x;
    if(n <= 2*v + 1) {
        count = 0;
        ans = "";
        for(int i = 0; i < n; ++i) ans += 'a';
        solve(0, true);        
    }
}