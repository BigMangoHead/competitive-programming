#include <iostream>
#include <vector>
#include <cmath>
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
    vector<pair<int, int>> p1;
    vector<pair<int, int>> p2;

    int m = sqrt(n) * 2 + 2;
    vector<vector<int>> b(2*m, vector<int>(2*m, 0));
    vector<vector<int>> t(m, vector<int>(m, 0));

    int d = 0;
    int count = 0;
    while (count < 2*n) {
        for (int x=0; x <= d; x++) {
            if ((x % 2 == 1 && (d - x) % 2 == 0) && d - x > 1) p1.push_back({x, d-x-1});
            if (x % 2 != 1 || (d - x) % 2 != 1) p1.push_back({x, d - x});
            p2.push_back({x, d-x});
            count++;
        }
        d++;
    }
    //for (auto& v : p1) cout << '(' << v.first << ' ' << v.second << ')' << ' ';
    //cout << endl;

    int x1 = 0;
    int x2 = 0;
    for (int i=0; i < n; i++) {
        if (a[i] == 0) {
            while (t[p2[x2].first][p2[x2].second] == 1) x2++;
            cout << 3*p2[x2].first+1 << ' ' << 3*p2[x2].second+1 << '\n';
            t[p2[x2].first][p2[x2].second] = 1;
            b[2*p2[x2].first][2*p2[x2].second] = 1;
        } else {
            while (b[p1[x1].first][p1[x1].second] == 1) {
                x1++;
            }
            int bx = p1[x1].first;
            int by = p1[x1].second;
            cout << 3*(bx / 2) + (bx % 2) + 1 << ' ' << 3*(by / 2) + (by % 2) + 1 << '\n';
            b[bx][by] = 1;
            t[bx/2][by/2] = 1;
        }
    }
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
