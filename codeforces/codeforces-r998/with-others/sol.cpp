#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define entry tuple<int, int, int>

void run() {
    int n, k;
    cin >> n >> k;

    vector<int> best(k+1, INT_MAX);
    vector<string> bestres(k+1);
    vector<vector<entry>> matrix(k+1);

    for (int d=0; d < 30; d++) {

        if (d == 0) {
            int sum = (k*(k+1)) / 2;
            best[sum % (k+1)] = sum;
            bestres[sum % (k+1)] = "0";
            matrix[sum % (k+1)].push_back({0, 0, sum});

            continue;
        }
        for (int x=1; x <= k; x++) {
            int thenine = 9*d;
            int sum = 0;
            for (int y=0; y < x; y++) {
                sum += thenine;
                thenine--;
            }
            for (int y=0; y <= k-x; y++) {
                sum += y+1;
            }
            matrix[sum % (k+1)].push_back({d, x, sum});
            if (sum < best[sum % (k+1)]) {
                best[sum % (k+1)] = sum;
                string res = "";
                for (int i=0; i < d-1; i++) {
                    res += '9';
                }
                res = res + ((char) (((int) '9') - x+1));
                bestres[sum % (k+1)] = res;
            }
        }
    }

    if (n >= best[n % (k+1)]) {
        string r = bestres[n % (k+1)];
        n -= best[n % (k+1)];
        n /= k+1;
        for (int i=0; i < n; i++) {
            r = '1' + r;
        }
        cout << r << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}