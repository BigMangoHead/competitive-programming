#include <algorithm>
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
        a[i] = x;
    }
    sort(a.begin(), a.end());
    cout << a[n-1] - a[0] << "\n";

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
