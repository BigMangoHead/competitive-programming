#include "bits/stdc++.h"
using namespace std;
#define ll long long

void run() {
    int x, y;
    cin >> x >> y;
    if (y > x+1) {cout << "NO" << endl; return;}
    if ((x + 1) % 9 == (y % 9)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
