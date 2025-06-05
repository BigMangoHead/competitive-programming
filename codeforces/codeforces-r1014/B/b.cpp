#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int count = 0;
    for (int i=0; i < n; i++) {
        if (i % 2 == 0) count += a[i] - '0';
        else count += b[i] - '0';
    }
    if (count > n/2) {
        cout << "NO\n";
        return;
    }

    count = 0;
    for (int i=0; i < n; i++) {
        if (i % 2 == 1) count += a[i] - '0';
        else count += b[i] - '0';
    }
    if (count > (n+1)/2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
