#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    ll l, r;
    cin >> l >> r;

    vector<int> a(n+2);
    vector<int> p(n+2);
    a[0] = 0; p[0] = 0;
    int cur = 0;
    for (int i=1; i <= n; i++) {
        cin >> a[i];
        cur ^= a[i];
        p[i] = cur;
    }
    if (n % 2 == 0) {
        n++;
        a[n] = p[n / 2];
        p[n] = p[n-1] ^ a[n];
    }

    int res = 0;
    while ((l / 2) % 2 == 0 && l/2 > n) {
        res ^= p[n];
        l /= 2;
    }

    if (l/2 > n) res ^= p[n];
    else if (l > n) res ^= p[l/2];
    else res ^= a[l];

    cout << res << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
