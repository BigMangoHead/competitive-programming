#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int fib[10] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> w(m), l(m), h(m);
    for (int i=0; i < m; i++) {
        int x;
        cin >> x;
        w[i] = x;
        cin >> x;
        l[i] = x;
        cin >> x;
        h[i] = x;
        if (w[i] > l[i]) swap(l[i], w[i]);
        if (w[i] > h[i]) swap(w[i], h[i]);
        if (l[i] > h[i]) swap(l[i], h[i]);
    }

    int a = fib[n-1];
    int b = fib[n-2];
    for (int i=0; i < m; i++) {
        if (h[i] >= a + b && w[i] >= a && l[i] >= a) cout << 1;
        else cout << 0;
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
