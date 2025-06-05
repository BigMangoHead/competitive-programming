#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    
    vector<vector<int>> works(n, vector<int>(m, 0));
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (a[i][j] != 1) break;
            works[i][j]++;
        }
    }
    for (int j=0; j < m; j++) {
        for (int i=0; i < n; i++) {
            if (a[i][j] != 1) break;
            works[i][j]++;
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (a[i][j] == 1 && works[i][j] == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
