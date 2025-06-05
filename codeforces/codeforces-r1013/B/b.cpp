#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int count = 0;
    int cur = INT_MAX;
    int curs = 0;
    for (auto& x : a) {
        curs++;
        cur = min(cur, x);
        if (cur*curs >= s) {
            cur = INT_MAX;
            curs = 0;
            count++;
        }
    }
    cout << count << endl;
}

int main(void) {
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
