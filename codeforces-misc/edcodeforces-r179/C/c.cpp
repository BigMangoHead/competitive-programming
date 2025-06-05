#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ll long long
#define int ll

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    int best = LONG_LONG_MAX;
    int len = 1;
    int v = a[0];
    for (int i=1; i < n; i++) {
        if (a[i] == a[i-1]) {
            len++;
        } else {
            best = min(best, (n - len)* v);
            v = a[i];
            len = 1;
        }
    }
    best = min(best, (n-len)*v);
    cout << best << '\n';
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
