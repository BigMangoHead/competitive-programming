#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int l, r, k;
    cin >> l >> r >> k;
    int res = (r / k) - l + 1;
    cout << max(res, 0) << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}