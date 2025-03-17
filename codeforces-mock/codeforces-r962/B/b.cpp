#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    int k;
    cin >> n >> k;
    vector<vector<int>> res(n/k, vector<int>(n/k));
    for (int i=0; i < n; i++) {
        string x;
        cin >> x;
        for (int j=0; j < n; j++) {
            
            if (i % k == 0 && j % k == 0) {
                cout << x[j];
            }
        }
        if (i % k == 0) cout << endl;
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