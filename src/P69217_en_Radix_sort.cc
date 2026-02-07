/*
Radix sort is a sorting algorithm that uses the fact that the elements inside a
computer are usually made up of bits, or digits in general, or characters. Here,
we will suppose that we need to sort a sequence of words made up only of
lowercase letters, all with the same length.

To implement radix sort (in one of its variants), we need a queue for each
possible character, and another queue @Q@. We start with all the words in @Q@.
We take out all the words in @Q@ and store each of them in the queue
corresponding to its last character. Afterwards, the words are taken out from
the ‘a’ queue, from the ‘b’ queue, …, from the ‘z’ queue, in this order, and we
store them in @Q@ again. Now we do the same again but with respect to the
penultimate character. We iterate this process until the first character is
used. In the end, @Q@ contains all the words in order.

For instance, suppose that the words are

was had him her way him the hat After sorting them with respect to the third
character, we have

had the him him her was hat way Now we sort with respect to the second
character, and we obtain

had was hat way her the him him Note that, if we deleted the first character of
each word, the words would already be in order. Finally, we sort with respect to
the first character:

had hat her him him the was way Input

Input consists of a sequence of words of the same length made up only of
lowercase letters.

Output

Print a line with the words in increasing order.

Observation

If you sorted the given words using any other efficient method, you would obtain
the asked result and the Judge would not detect this. But then you would not
practise the use of queues.
*/

//reskold73, 2025-11-14

#include <iostream>
#include <queue>

using namespace std;

using qs = queue<string>;
using vqs = vector<qs>;

const int auxlen = int('z' - 'a' + 1);

int main () {
    qs ans;
    string s;
    while(cin >> s) ans.push(s);
    int n = s.size();
    vqs aux (auxlen);
    while(n--) {
        while(not ans.empty()) {
            string temp = ans.front(); ans.pop();
            aux[temp[n]-'a'].push(temp);            
        }
        for(int i = 0; i < auxlen; ++i) {
            while(not aux[i].empty()) {
                ans.push(aux[i].front()); aux[i].pop();
            }
        }
    }
    if(not ans.empty()) {
        cout << ans.front(); ans. pop();
    } 
    while(not ans.empty()) {
        cout << ' ' << ans.front(); ans.pop();
    }
    cout << endl;

}