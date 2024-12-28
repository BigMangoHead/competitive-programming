#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

void fails() {
    cout << "No" << endl;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    int ma = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> a[i][j];
            ma = max(ma, a[i][j]);
        }
    }
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            cin >> b[i][j];
            ma = max(ma, b[i][j]);
        }
    }

    vector<int> force(m, 0);
    while (ma > 0) {
        for (int i=0; i < n; i++) {
            bool superWorks = true;
            for (int j=0; j < m; j++) {
                if ((a[i][j] & 1) != (b[i][j] & 1)) {
                    superWorks = false;
                    break;
                }
            }
            if (superWorks) continue;
            superWorks = true;
            for (int j=0; j < m; j++) {
                if ((b[i][j] & 1) != 0) {
                    superWorks = false;
                    break;
                }
            }
            if (superWorks) continue;

            bool mustAnd = false;
            for (int j=0; j < m; j++) {
                if ((a[i][j] & 1) == 1 && (b[i][j] & 1) == 0) {
                    mustAnd = true;
                }
            }

            if (mustAnd) {
                for (int j=0; j < m; j++) {
                    if ((b[i][j] & 1) == 1) {
                        if (force[j] == -1) {
                            fails(); return;
                        }
                        force[j] = 1;
                    }
                }
            } else {
                for (int j=0; j < m; j++) {
                    if ((a[i][j] & 1) == 0 && (b[i][j] & 1) == 1) {
                        if (force[j] == -1) {
                            fails(); return;
                        }
                        force[j] = 1;
                    }

                    if ((b[i][j] & 1) == 0) {
                        if (force[j] == 1) {
                            fails(); return;
                        }
                        force[j] = -1;
                    }
                }
            }
        }
        for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            a[i][j] /= 2;
            b[i][j] /= 2;
        }
    }
        ma /= 2;
    }

    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //clog << gcd(3333000, 7890) << endl;

    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}