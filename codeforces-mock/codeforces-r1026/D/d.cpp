#include <iostream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;
#define int long long
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = x;
    }

    vector<vector<pair<int, int>>> edges(n);
    vector<int> in(n, 0);
    for (int i=0; i < m; i++) {
        int x;
        cin >> x;
        int y, z;
        cin >> y >> z;
        x--;
        y--;
        in[y]++;
        edges[x].push_back({y, z});
    }

    auto bs_check = [&](const int& che) {
        vector<int> mab(n, -1);
        vector<int> incur(n, 0);
        queue<int> q;
        q.push(0);
        mab[0] = b[0];
        while (q.size() > 0) {
            int x = q.front();
            q.pop();
            if (incur[x] != in[x]) continue;
            incur[x]++;
            for (auto y : edges[x]) {
                incur[y.first]++;
                q.push(y.first);
                if (mab[x] < y.second || y.second > che) continue;
                mab[y.first] = max(mab[x] + b[y.first], mab[y.first]);
            }
        }
        if (mab[n-1] != -1) return true;
        return false;
    };

    int low = 1;
    int high = 1000000005;
    while (low < high) {
        int mid = (low + high) / 2;
        if (bs_check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    if (low > 1000000000) cout << "-1\n";
    else cout << low << '\n';
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
