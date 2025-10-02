/*
At this stage, you surely already know that some problems are so classic that blah, blah, blah. Nothing new with this problem. Now, we ask you to compute the minimum cost to insert letters into or to modify letters from two words w1 and w2 to make them identical. Both words are made up of only letters chosen among the n smallest lowercase letters (for instance, for n=4, the alphabet is {a, b, c, d}). For every letter (call it x), inserting an x in any place in any word has cost Ix. The cost to transform a letter x into a letter y is given by ⌈(Ix+Iy)/4⌉, i.e., a fourth part, ceiling, of the sum fo the insertion costs Ix and Iy.

Input

Input consists of several cases. Each case begins with 2≤ n≤ 26, followed by n strictly positive natural numbers Ia, Ib, Ic, …. Follow two words w1 and w2 made up of between 1 and 1000 lowercase letters chosen among the n smallest letters. Assume 1≤ Ix≤ 1000 for every letter x.

Output

For every case, print the minimum cost to make w1 and w2 identical.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;

int main () {
    
}