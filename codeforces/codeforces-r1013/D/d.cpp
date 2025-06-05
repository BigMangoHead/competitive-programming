#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define int ll

void run() {
    int n, m, k;
    cin >> n >> m >> k;
    auto bs_check = [&](const int& x) {
        ll blank = m / (x + 1);
        blank *= n;
        return (n*m - blank >= k);
    };

    int low = 1;
    int high = m;
    while (low < high) {
        int mid = (low + high) / 2;
        if (bs_check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
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
