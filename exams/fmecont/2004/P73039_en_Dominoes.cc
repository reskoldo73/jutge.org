/*
Anna and Bernard play the following game: First, they invent five words each. Later, and
alternatively, Anna writes her first word, Bernard writes his first word, Anna writes her second word, 
Bernard writes his second word, and so on. The first to write a word that does
not start with the same character with which ends the previous word, loses. (The first word,
always Anna’s, can start with any character.) If after writing the 10 words nobody loses, the
game ends in a draw.
Write a program to decide who wins every game.
Input
Input begins with a natural number indicating the number of games. Follow the 10 words of
every game, in this order: the first word of Anna, the first word of Bernard, the second word
of Anna, etcetera.
Output
For each game, print a line with ‘A’, ‘B’, or ‘=’, depending on whether Anna wins, Bernard
wins, or it is a tie.
*/

#include <iostream>

using namespace std;

char game() {
    string word;
    cin >> word;
    char last = word.back();
    bool a = true, b = true;

    for(int j = 1; j < 10; ++j) {
        cin >> word;
        if(a and b) {
            if(word[0] != last) {
                if(j%2 == 0) a = false;
                else b = false;
            }
            last = word.back();
        }
    }
    if(not a) return 'B';
    else if(not b) return 'A';
    return '=';
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cout << game() << endl;
    }
}