#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(q);
    for (int i= 0; i < q; i++) {
        cin >> a[i];
    }

    int l, r, b1, b2;
    l = r = 0;
    b1 = b2 = m-1;
    bool le = false;
    bool re = false;
    bool be = true;

    auto incRight = [&]() {
        if (re) r++;
        if (be && b2 >= n - r) {
            r--;
        }
        if (l + r > n) {
            r--;
        } 
    };
    auto incMidLeft = [&] {
        if (be) b1--;
        if (be && b1 < l) {
            b1++;
        }
    };
    auto incMidRight = [&] {
        if (be) b2++;
        if (be && b2 >= n - r) {
            b2--;
        }
    };
    auto incLeft = [&] {
        if (le) l++;
        if (be && b1 < l) {
            l--;
        }
        if (l + r > n) {
            l--;
        } 
    };

    for (int j=0; j < q; j++) {
        int i = a[j] - 1;
        if (i < l) {
            re = true;
            incMidLeft();
            incRight();
        } else if (i < b1) {
            incMidLeft();
            incLeft();
            incRight();
        } else if (i <= b2) {
            if (b1 == b2) {
                be = false;
            }
            re = true;
            le = true;
            incRight();
            incLeft();
        } else if (i < n - r) {
            incMidRight();
            incRight();
            incLeft();
        } else {
            le = true;
            incLeft();
            incMidRight();
        }
        //clog << l << " " << b1 << " " << b2 << " " << r << endl;

        int res = l + r;
        if (be) res += 1 + b2 - b1;
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i << endl;
        run();
    } 
}