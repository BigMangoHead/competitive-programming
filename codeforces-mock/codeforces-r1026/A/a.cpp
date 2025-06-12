#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());

    int pos1=-1, pos2=n;
    for (int i=0; i < n-1; i++) {
        if (a[i] % 2 != a[i + 1] % 2) {
            pos1 = i;
            break;
        }
    }
    for (int i=n-1; i >=1; i--) {
        if (a[i] % 2 != a[i - 1] % 2) {
            pos2 = i;
            break;
        }
    }

    if ((a[0] + a[n-1]) % 2 == 0) {
        cout << 0 << '\n';
        return;
    }
    cout << min(pos1, n - 1 - pos2) + 1 << '\n';
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
