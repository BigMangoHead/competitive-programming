#include <iostream>
#include <vector>
#include <set>
#include <numeric>
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
    
    int g = a[0];
    for (int i=1; i < n; i++) {
        g = gcd(g, a[i]);
    }
    int count = 0;
    for (int x : a) {
        if (x == g) {
            count++;
        }
    }
    if (count > 0) {
        cout << n - count << '\n';
        return;
    }

    set<int> as;
    for (int x : a) {
        as.insert(x);
    }
    set<int> b = as;
    set<int> c;
    bool flag = false;
    int k =1;
    for (; k < 7; k++) {
        for (int x : a) {
            for (int y : b) {
                int v = gcd(x, y);
                if (v == g) {
                    //clog << k << ' ' << x << ' ' << y << ' ' << v << endl;
                    flag = true;
                    break;
                }
                c.insert(v);
            }
            if (flag) break;
        }
        b = c;
        c.clear();
        if (flag) break;
    }
    cout << k - 1 + n << '\n';
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
