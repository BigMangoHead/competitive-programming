#include <climits>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

bool checkPrime(int x) {
    const int n = sqrt(x);
    for (int i=2; i <= n; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(m);
    for (int i=0; i < m; i++) {
        cin >> pos[m-1-i];
    }

    vector<int> fCount(n+1, 0);
    //vector<int> compCheck(n+1, 0); // Checks if composite or not
    for (int i=2; i <= n; i++) {
        if (!checkPrime(i)) {
            continue;
        }

        for (int j=1; i*j <= n; j++) {
            int x = j*i;
            int c = 0;
            while (x % i == 0) {
                c++;
                x /= i;
            }
            fCount[i*j] += c;
        }
    }

    vector<int> res(n);
    for (int i=0; i < n; i++) {
        //cout << "e" << fCount[i+1] << " ";
        //if (compCheck[i+1] >= 2 && fCount[i+1] == 1) {
        //    fCount[i+1]++;
        //}
        if (fCount[i+1] >= m) {
            cout << -1 << endl;
            return;
        }
        res[i] = pos[fCount[i+1]];
    }

    for (auto e : res) {
        cout << e << " ";
    }
    cout << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}