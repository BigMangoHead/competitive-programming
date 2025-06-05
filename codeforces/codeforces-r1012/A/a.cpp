#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int x, y, a;
    cin >> x >> y >> a;
    a %= x+y;
    if (a - x < 0) cout << "NO" << endl;
    else cout <<"YES\n";
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
