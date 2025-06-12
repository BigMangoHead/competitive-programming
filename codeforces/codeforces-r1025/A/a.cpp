#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> an(n);
    bool allone = true;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        an[i] = x;
        if (x == 0) allone = false;
    }
    if (allone) {
        cout << "YES\n";
        return;
    }

    int prev = an[0];
    for (int i=1; i < n; i++) {
        if (an[i] == 0 && an[i-1] == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
