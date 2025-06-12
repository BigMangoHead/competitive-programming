#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    string s;
    cin >> s;
    int count = 0;
    const int n = s.size();
    bool flag = true;
    for (int i=0; i < n-1; i++) {
        if (s[i] == '(') {
            count ++;
        } else {
            count--;
        }
        if (count == 0) flag = false;
    }
    if (flag) cout << "NO\n";
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
