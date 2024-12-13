#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, x;
    cin >> n >> x;
    long long ma = 0;
    long long total = 0;
    for (int i=0; i < n; i++) {
        long long a;
        cin >> a;
        ma = max(ma, a);
        total += a;
    }
    cout << max(ma, (total - 1) / x + 1) << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}