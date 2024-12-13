#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    int ma = 0;
    int mi = INT_MAX;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        ma = max(ma, x);
        mi = min(mi, x);
    }
    cout << (ma - mi)*(n - 1) << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}