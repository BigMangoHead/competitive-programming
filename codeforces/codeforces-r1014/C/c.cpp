#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }
    int ec = 0;
    for (int i=0; i < n; i++) {
        if (a[i] % 2 == 0) ec++;
    }

    if (ec == 0 || ec == n) {
        cout << *max_element(a.begin(), a.end()) << "\n";
        return;
    }

    cout << sum - (n - ec - 1) << "\n";
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
