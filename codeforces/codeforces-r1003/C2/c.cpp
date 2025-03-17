#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    for (int i=0; i < m; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);

    for (int i=1; i < n; i++) {
        int low = 0;
        int high = m;
        while (low < high) {
            int mid = (low + high) /2;
            if (b[mid] - a[i] >= a[i-1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low != m && a[i] >= a[i-1]) { // don't change if no operation w/ b can be done
            a[i] = min(a[i], b[low] - a[i]);
        } else if (low != m) {
            a[i] = b[low] - a[i];
        }
        if (a[i-1] > a[i]) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}