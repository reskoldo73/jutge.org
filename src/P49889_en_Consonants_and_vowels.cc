/*
Write a program that reads n consonants and n vowels, and prints all the words
that can be made up by using each letter exactly once. The words must begin with
a consonant, and alternate consonants and vowels. In this exercise, we will
assume that ‘y’ is a vowel.

Input

Input consists of a natural number n between 1 and 6, followed by n different
consonants and n different vowels. Both consonants and vowels are given in
alphabetical order.

Output

Print the words that can be made up with the 2n given letters, starting with a
consonant and always alternating consonants and vowels. Print the words in
alphabetical order, one per line.
*/

//reskoldo73, 2025-09-10

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;

vector<vi> allperm;
vi perm;
vb avail;
vs ans;
int n;

string cons, vows;


void pushans() {
    int allsize = allperm.size();
    for(int i = 0; i < allsize; ++i) {
        for(int j = 0; j < allsize; ++j) {
            string temp = "";
            for(int k = 0; k < n; ++k) {
                temp += (char)cons[allperm[i][k]];
                temp += (char)vows[allperm[j][k]];
            } 
            ans.push_back(temp);
        }
    }
}

void solve(int pos) {
    if(pos == n) {
        allperm.push_back(perm);
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(avail[i]) {
            perm[pos] = i;
            avail[i] = false;
            solve(pos+1);
            avail[i] = true;
        }
    }  
}

int main () {
    cin >> n;
    cin >> cons >> vows;
    perm = vi(n);
    avail = vb(n, true);
    allperm = vector<vi>();
    solve(0);
    ans = vs();
    pushans();
    sort(ans.begin(), ans.end());
    for(string x : ans) cout << x << "\n";
}

