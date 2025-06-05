#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int a, b,c, d;
    cin >> a >> b >> c >> d;
    if (min(b, d) <= min(a, c)) {
        cout << "Gellyfish" << '\n';
    } else {
        cout << "Flower" << '\n';
    }
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
