#include <climits>
#include <iostream>
using namespace std;
#define ll long long

void run() {
    int l, r;
    cin >> l >> r;
    int x, y, z;
    x = l; z = r;
    int m = 0;
    int m2 =0;

    for (int b=0; b < 31; b++) {
        if ((x & (1 << b)) != (z & (1 << b))) m = b;
    }
    y = x;

    int lastChange = 0;
    for (int i=0; i < m; i++) {
        if ((x & (1 << i)) == (z & (1 << i))) {
            if ((x & (1 << i)) > 0) {
                lastChange = 0;
                y = y & (INT_MAX - (1 << i));
            } else {
                lastChange = 1;
                y = y | (1 << i);
            }
        }
    }
    //clog << y <<endl;
    if (lastChange == 0) {
        y += (1 << (m));
    }

    cout <<x << " " << y << " " << z << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i+1 << endl;
        run();
    } 
}