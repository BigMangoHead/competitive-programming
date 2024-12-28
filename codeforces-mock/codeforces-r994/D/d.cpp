#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m, LONG_LONG_MAX));
    for (int i = n-1; i >= 0; i--) {
        for (int c=0; c < m; c++) {

            ll init = ((ll) c)*k;
            ll cost;
            if (i == n-1) cost = init;
            else {
                cost = init + dp[i+1][m-1];
            }

            for (int j=m-1; j >= 0; j--) {

                if (i == n-1) cost += a[i][(j+c) % m];
                else {
                    cost = min(init + dp[i+1][j] + a[i][(j+c) % m], cost + a[i][(j+c) % m]);
                }

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    //if (n >2 && m > 2) clog << dp[2][2] << endl;
    cout << dp[0][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i+1 << endl;; 
        run();
    }
}