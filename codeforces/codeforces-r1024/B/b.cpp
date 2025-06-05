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
        a[i] = abs(x);
    }
    if (n == 1 || n == 2) {
        cout << "YES\n";
        return;
    }
    int target = a[0];
    sort(a.begin(), a.end());

    if (a[(n+2)/2] > target) cout << "YES";
    else cout << "NO";
    cout << endl;
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
