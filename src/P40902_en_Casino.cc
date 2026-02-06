/*
Write a program to compute the profits of the players of a casino. The
operations that can be done are: enter the casino, leave the casino, or win a
quantity (maybe negative) of money.

Input

Input consists of several operations. If a player enters the casino, we have his
name followed by “enters”. If a player leaves the casino, we have his name
followed by “leaves”. When a player wins a quantity (maybe negative), we have
his name followed by “wins” followed by the quantity of money won (an integer
number).

Output

Every time that a player leaves the casino, print the total quantity of money
that he or she has won (it can be negative).

At the end, print a line with 10 dashes, followed by a list sorted by name of
the profits of the players that did not left yet. Print also an error line for
each incorrect operation, that is, entering the casino when the player is
already inside, or leaving or winning money when the player has not entered yet.
*/

//reskoldo73, 2025-11-24

#include <iostream>
#include <map>

using namespace std;

int main () {
    map<string, int> casino;
    string s;
    while(cin >> s) {
        string t;
        cin >> t;
        if(t == "enters") {
            auto temp = casino.insert({s,0});
            if(not temp.second) cout << s << " is already in the casino" << endl;
        }
        else if (t == "leaves") {
            auto it = casino.find(s);
            if(it != casino.end()) {
                cout << s << " has won " << it->second << endl;
                casino.erase(it);
            }
            else cout << s << " is not in the casino" << endl;
        }
        else { //t == "wins"
            int temp;
            cin >> temp;
            auto it = casino.find(s);
            if(it != casino.end()) it->second += temp;
            else cout << s << " is not in the casino" << endl;
        }
    }
    cout << "----------" << endl;
    for(auto p : casino) cout << p.first << " is winning " << p.second << endl;
}