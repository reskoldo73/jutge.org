/*
Enough of annoying bulls, poor animals. Bullfights have to modernize, and to this end, we proposed that bulls were substituted by fearsome bull robots, with truck diesel engines, sensors of motion, heat and vision, and an artificial intelligence with a fairly bad mood. Unfortunately, the designed bull robot was a little too dangerous, so after a few nonfatal incidents (it was a really sensible idea to use in those early tests foam rubber horns instead of steel diamond ones), the bullfighters’ union informed us that, or we make the bull a bit more predictable, or the bull is going to be fighted “by our aunt”.

To this end we ask for your help. Write a program that, given an image of w × h pixels as seen by the bull robot, where every pixel is a number between 0 and 255 indicating the intensity of red color at this point in the image, finds out which is the redder square of c × c pixels, i.e., such that the average of the intensities of its pixels is maximum.

Input

Input begins with three natural numbers w, h and c. Follow h lines, each one with w natural numbers between 0 and 255. You can assume 2≤ w,h≤ 500 and 1≤ c≤ min(w, h).

Output

Print the row and the column of the upper-left corner of the square that has the maximum red intensity. If there is more than one square with maximum intensity, print the one with smaller row, and if there are several, the one with smaller column. Both the rows and the columns are numbered starting at 0.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int w, h, c;
vvi rect;

void read() {
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            int& temp = rect[i][j];
            cin >> temp;
            temp += rect[i][j-1];
            temp += rect[i-1][j];
            temp -= rect[i-1][j-1];
        }
    }
}

void solve() {
    int max = -1;
    int x = 0, y = 0;
    for(int i = 0; i <= h-c; ++i) {
        for(int j = 0; j <= w-c; ++j) {
            int temp = rect[i+c][j+c] + rect[i][j] - rect[i][j+c] - rect[i+c][j];
            if(temp > max) {
                max = temp;
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << endl;    
}

int main() {

    cin >> w >> h >> c;
    rect = vvi(h+1, vi(w+1, 0));
    read();
    solve();
}