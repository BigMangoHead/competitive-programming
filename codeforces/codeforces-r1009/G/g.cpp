#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<ll> a(2*n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    copy(a.begin(), a.begin() + n, a.begin() + n);
    vector<vector<ll>> dp(n+1, vector<ll>(n)); // size, left
    for (int i=0; i < n; i++) {
        dp[0][i] = 0;
    }
    
    // Solve for all segments
    for (int s=1; s <= n; s++) {
        for (int l=0; l < n; l++) {
            ll & cur = dp[s][l];

            // Either start or end unused
            cur = max(dp[s-1][l], dp[s-1][(l+1) % n]);

            // If both used, two cases
            // Case 1: Both used in same triangle
            for (int i=l+1; i < l+s - 1; i++) {
                cur = max(cur, a[i]*a[l]*a[l+s-1] + dp[i - (l+1)][(l+1) % n] + dp[l+s-i-2][(i+1) % n]);
            }

            // Case 2: Used in different triangles
            for (int i=0; i < s; i++) {
                cur = max(cur, dp[i][l] + dp[s - i][(l + i) % n]);
            }
        }
    }

    cout << dp[n][0] << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
