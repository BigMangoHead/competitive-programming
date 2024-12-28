#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ma(n, vector<int>(m));
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> ma[i][j];
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            int x = 0;
            if (i > 0) {
                x = max(x, ma[i - 1][j]);
            } 
            if (i < n-1) {
                x = max(x, ma[i + 1][j]);
            }
            if (j > 0) {
                x = max(x, ma[i][j-1]);
            }
            if (j < m-1) {
                x = max(x, ma[i][j+1]);
            }

            if (x >= ma[i][j]) {
                continue;
            } else {
                ma[i][j] = x;
            }
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}