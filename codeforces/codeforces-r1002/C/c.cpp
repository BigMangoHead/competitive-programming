#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> ps(n, 0);

    for (int i=0; i < n; i++) {
        int j=n-1;
        while (j >= 0 && a[i][j] == 1) {
            ps[i]++;
            j--;
        }
    }
    sort(ps.begin(), ps.end());
    int res = 0;
    // Test every res, could BS but who cares
    bool flag = false;
    for (int i=0; i < n; i++) {
        int ic = i;
        for (int j=n-1; ic >= 0; j--) {
            if (ps[j] < ic) {
                flag = true;
                break;
            }
            ic--;
        }
        if (flag) break;
        res = i;
    }
    
    cout << res + 1 << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}