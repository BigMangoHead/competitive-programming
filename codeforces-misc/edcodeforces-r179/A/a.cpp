#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    ll v1 = 1;
    ll v2 = 1;
    ll v3 = 0;
    int t = 2;
    while (n > min(min(v1, v2), v3)) {
        v3 = 2*v1 + 1;
        t++;
        if (n <= min(min(v1, v2), v3)) break;
        v1 = 2*v2 + 1;
        t++;
        if (n <= min(min(v1, v2), v3)) break;
        v2 = 2*v3 + 1;
        t++;
    }
    cout << t << endl;
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
