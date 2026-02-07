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