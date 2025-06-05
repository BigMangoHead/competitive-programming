#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    
    ll sum = 0;
    for (int i=n-1; i >= 0; i--) {
        sum += a[i];
        a[i] = sum;
    }
    if (sum*k < x) {
        cout << 0 << '\n';
        return;
    }
    
    auto bs_check = [&](const ll& y) {
        ll cur = a[y % n];
        cur += sum*((n*k-y-1) / n);
        return cur >= x;
    };

    ll low = 0;
    ll high = n*k-1;
    while (low < high) {
        ll mid = (low + high+1) / 2;
        if (bs_check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low+1 << '\n';
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
