/*
Consider the following game. You start with an empty set of words S. Afterwards, you will be given words one by one. For every given word w, if w is not in S, insert w in S, and if w is already in S, remove w from S. At the end of the process, you must list

the words that belong to S;
the words that have been in S, but that finally are not in S.
Input

Input consists of one or more cases. Every case consists of words made up of only lowercase letters. Each case ends with “END”, except the last case, which ends with “QUIT”.

Take into accout that the “big” private test cases have words repeated many times. If your program uses too much memory, you may receive a “WA” veredict.

Output

For every case, print its game number starting at 1. Then, print the words that are in S, followed by a blank line, followed by the words that are not in S but that at some moment were in S. The first list must be sorted in alphabetical order. The second list must be sorted by the length of the words (first the shorter words), using alphabetical order to break ties. Separate the output of two consecutive games by a blank line.
*/

#include <iostream>
#include <set>

using namespace std;

struct criterion{
    bool operator() (const string &a, const string& b) const {
        int as = a.size();
        int bs = b.size();

        if(as == bs) return a < b;
        return as < bs;
    }
};



int main () {
    string s;
    while(cin >> s) {
        set<string> has;
        set<string, criterion> had;
    }
}