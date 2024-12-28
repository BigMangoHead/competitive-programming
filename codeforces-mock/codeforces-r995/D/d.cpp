#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    ll s = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }

    ll l = s -y;
    ll u = s - x;

    sort(a.begin(), a.end());

    ll count = 0;
    for (int i=0; i < n - 1; i++) {
        if (a[i] + a[n-1] < l) {
            continue;
        }
        if (a[i] + a[i+1] > u) {
            break;
        }
        int low = i+1;
        int high = n-1;
        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (a[i] + a[mid] > u) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        int t = low;
        low = i+1;
        high = n-1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (a[i] + a[mid] < l) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int b = low;

        count += t - b + 1;
    }

    cout << count << endl;
    


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}