#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < m; i++) {
        cin >> b[m-i-1];
    }

    vector<vector<int>> precal(m, vector<int>(n+1));
    vector<vector<pair<int, int>>> result(n+1, vector<pair<int, int>>(m)); // val, ways

    for (int i=0; i < m; i++) {
        precal[i][0] = 0;
        int ptr = n-1;
        int sum = a[n-1];
        for (int j=n-1; j >= 0; j--) {
            while (ptr > 0 && sum + a[ptr-1] <= b[i]) {
                ptr--;
                sum += a[ptr];
            }
            if (ptr > j) {
                precal[i][j+1] = -1;
                ptr--;
            } else if (sum > b[i]) {
                precal[i][j+1] = -1;
            } else precal[i][j+1] = ptr;
            sum -= a[j];
        }
    }

    for (int j=0; j < m; j++) {
        result[0][j].first = 0;
        result[1][j].first = j;
        if (a[0] > b[j]) {
            result[1][j].first = INT_MAX;
        }
    }

    for (int i=1; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (precal[j][i+1] == -1) {
                result[i+1][j] = INT_MAX;
                continue;
            }
            result[i+1][j] = *min_element(result[precal[j][i+1]].begin() + j, result[precal[j][i+1]].end()) + j;
            if (result[i+1][j] < 0) {
                result[i+1][j] = INT_MAX;
            }
        }
    }

    int res = *min_element(result[n].begin(), result[n].end());
    if (res == INT_MAX) res = -1;

    cout << res << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}