#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i < m; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    int k = m - 1;
    for (int i=0; i < n; i++) {
        if (i % 2) for (int j=0; j < 6; j++) {
            if (j % 2) cout << a[i/2];
            else cout << a[k];
            cout<< ' ';
        }
        else for (int j=0; j < 6; j++) {
            if (j % 2) cout << a[k];
            else cout << a[i/2];
            cout << ' ';
        }
        if (i % 2 == 1) k--;
        cout << '\n';
    }
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
