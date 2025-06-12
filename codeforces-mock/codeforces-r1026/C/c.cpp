#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        d[i] = x;
    }
    int offset = 0;
    vector<pair<int, int>> o(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        if (d[i] == 1) offset++;
        o[i] = {x - offset, y - offset};
    }

    vector<int> top(n);
    vector<int> bottom(n);
    int t = 0;
    int b = INT_MAX;
    for (int i=n-1; i >= 0; i--) {
        b = min(b, o[i].second);
        t = max(t, o[i].first);
        top[i] = t;
        bottom[i] = b;
    }

    int pos = 0;
    for (int i=0; i < n; i++) {
        if (d[i] == -1) {
            if (pos < bottom[i]) {
                pos++;
                d[i] = 1;
            } else {
                d[i] = 0;
            }
        }
        if (pos < o[i].first || pos > o[i].second) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int x : d) {
        cout << x << ' ';
    }
    cout << '\n';
    
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
