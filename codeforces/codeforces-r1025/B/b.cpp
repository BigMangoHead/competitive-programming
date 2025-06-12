#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int score(int x) {
    if (x == 1) return 0;
    x--;
    int t = 1;
    while (x > 1) {
        x >>= 1;
        t++;
    }
    return t;
}

void run() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int scn = score(n);
    int scm = score(m);
    int sca = min(score(a), score(1+n -a));
    int scb = min(score(b), score(1+m-b));
    if (scn - sca >= scm - scb) {
        scn = sca;
    } else {
        scm = scb;
    }

    cout << scn + scm + 1 << '\n';
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
