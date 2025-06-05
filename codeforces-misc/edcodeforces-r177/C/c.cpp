#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x-1;
    }
    vector<int> d(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        d[i] = x - 1;
    }
    
    vector<int> r(n, 0);
    int count  = 0;
    for (auto& v : d) {
        if (r[v] == 1) {
            cout << count << ' ';
            continue;
        }
        r[v] = 1;
        count++;
        while (true) {
            v = a[v];
            if (r[v] == 1) break;
            r[v] = 1;
            count++;
        }
        cout << count << ' ';
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
