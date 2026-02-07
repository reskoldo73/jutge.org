/*
This year four adventurers went on vacation to Potige, a city in Kerala (India),
and they discovered some Indians who speak a strange language called Malayalam.
As a language already in development (let’s say, like a beta version), it does
not have too many grammatical rules yet.

The main rule is that all words must pass the Dislex-Wonga test. This primitive
test consists in painting the letters of the word on a huge wall. Afterwards,
two Indians get on a stage, and they start reading (singing) the word, one
starting from the beginning and the other one from the end, in opposite
directions. The word passes the test if both Indians sing the same song.

Neuquen, the chief of the Potige tribe, imposes adding the necessary letters
until the word passes the Dislex-Wonga test, and charges a tax of one rupee on
each letter added. Your mission is to help the poor guy who invented the word,
so that he pays the least possible money to Neuquen.

Input

Input consists of several words w of length between 1 and 2000, made up only of
lowercase letters, uppercase letters, and digits.

Output

For every w, compute the minimum number of necessary characters to add in order
to pass the Dislex-Wonga test. If the answer is zero, print “Passes the
Dislex-Wonga test”.
*/

//reskoldo73, 2025-10-21

#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi memo;
string s;

int solve(int i, int j) {
    if(i >= j) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == s[j]) return memo[i][j] = solve(i+1, j-1);
    return memo[i][j] = 1 + min(solve(i+1, j), solve(i, j-1));
}

int main () {
    while(cin >> s) {
        int ssize = s.size();
        memo = vvi(ssize, vi(ssize, -1));
        int temp = solve(0, ssize-1);
        if(temp == 0) cout << "Passes the Dislex-Wonga test\n";
        else cout << temp << "\n";
    }
}