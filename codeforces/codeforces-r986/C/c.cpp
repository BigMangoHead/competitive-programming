#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, m;
    long long v;
    cin >> n >> m >> v;

    vector<int> taste(n);
    for (int i=0; i < n; i++) cin >> taste[i];

    vector<int> sectors(m);
    long long sum = 0;
    int secIndex = 0;
    for (int i=0; i < n; i++) {
        sum += taste[i];
        if (sum >= v) {
            sectors[secIndex] = i;
            secIndex++;
            sum = 0;
        }
        if (secIndex == m) break;
    }

    if (secIndex != m) {
        cout << -1 << endl;
        return;
    }

    vector<int> sectorsBack(m);
    secIndex = 0;
    sum = 0;
    for (int i=n-1; i >= 0; i--) {
        sum += taste[i];
        if (sum >= v) {
            sectorsBack[secIndex] = i;
            secIndex++;
            sum = 0;
        }
        if (secIndex == m) break;
    }


    int frontIndex = 0;
    int backIndex = sectorsBack[m-1] - 1;
    sum = 0;

    for (int i=0; i <= backIndex; i++) {
        sum += taste[i];
    }

    long long best = sum;
    int curSec = 1;
    while (curSec <= m) {

        int newFrontIndex = sectors[curSec-1] + 1;
        int newBackIndex;
        if (curSec < m) newBackIndex = sectorsBack[m-1-curSec] - 1;
        else newBackIndex = n-1;

        for (int i=frontIndex; i < newFrontIndex; i++) {
            sum -= taste[i];
        }
        for (int i=backIndex + 1; i <= newBackIndex; i++) {
            sum += taste[i];
        }

        best = max(best, sum);

        frontIndex = newFrontIndex;
        backIndex = newBackIndex;
        curSec++;
    }

    cout << best << endl; 
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}