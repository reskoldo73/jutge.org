/*
In this problem we consider the expressions defined as follows:

Every variable is a correct expresion;
if x is a correct expression, so is (x);
if x1 and x2 are correct expressions, so are (x1) − (x2);
nothing else is a correct expression.
For instance, if the set of variables is A, B, C, these are some correct expressions:

A    (A)    ((C))    (A)−(B)    ((A)−(B))−(A)
Write a program that, given two numbers n and m, prints the number of correct expressions of length exactly n that can be made up with m variables.

For instance, for n =7 and m=2 the result should be 6, corresponding to

(((A)))    (((B)))    (A)−(A)    (A)−(B)    (B)−(A)    (B)−(B)
Input

Input consists of several cases, each with two natural numbers n and m between 1 and 25.

Output

For every case, print the number of correct expressions of length exactly n that can be made up with m variables. This number will always be smaller than 109.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
}