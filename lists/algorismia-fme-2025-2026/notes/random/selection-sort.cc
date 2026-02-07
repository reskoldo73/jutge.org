#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

int n;
vi v;

void swap(int i, int j) {
    int aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

//cost = O(n²);
/*
Comparations: (n-1)*n/2 = O(n²)
Swaps: n-1 = O(n)

Better than insertion when dealing with hard to swap elements
*/
void sel_sort() {
    for(int i = 0; i < n; ++i) {
        int min =  v[i];
        int it = i;
        for(int j = i+1; j < n; ++j) {
            int temp = v[j];
            if(temp < min) {
                it = j;
                min = temp;
            }
        }
        if(i != it) swap(i, it);
    }
}

int main () {
    cin >> n;
    v = vi(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sel_sort();
    for(int x : v) cout << " " << x;
    cout << "\n";
}