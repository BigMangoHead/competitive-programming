#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p == 0 && q*n != p*m) cout << "NO\n";
    else cout << "YES\n";
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
