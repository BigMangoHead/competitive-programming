#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;

    vector<int> isPrime(n+1, 1);
    for (int a=2; a*a <= n; a++) {
        for (int b=a*a; b <= n; b += a) {
            isPrime[b] = 0;
        }
    }

    int cent;
    for (int i=n/6+1; i <= n; i++) {
        if (isPrime[i]) {
            cent = i;
            break;
        }
    }

    vector<int> used(n+1, 0);
    used[cent] = 1;
    cout << cent << ' ';
    for (int i=1; i <= n/6; i++) {
        used[cent + i] = 1;
        used[cent - i] = 1;
        cout << cent + i << ' ' << cent - i << ' ';
    }
    for (int i=1; i <= n; i++) {
        if (used[i] == 0) cout << i << ' ';
    }
    cout << endl;
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
