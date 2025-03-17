#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<ll> a(n);

    int even = 0;
    for (int i=0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        if (x % 2 == 0) even++;
    }

    ll res = 0;
    if (even > 0) {
        res = n - even + 1;
    } else {
        res = n - 1;
    }
    cout << res << "\n";

}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}