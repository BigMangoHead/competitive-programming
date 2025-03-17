#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    n *= 2;

    vector<int> b(n);
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    ll res = 0;
    for (int i=0; i < n; i++) {
        if (i >= n/2 - 1) res += b[i];
        else res -= b[i];
    }

    cout << b[n-1] << ' ' << res << ' ';
    cout << b[n-2] << ' ';
    for (int i=0; i < n/2-1; i++) {
        cout << b[i] << ' ' << b[n-3-i] << ' ';
    }
    cout << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
