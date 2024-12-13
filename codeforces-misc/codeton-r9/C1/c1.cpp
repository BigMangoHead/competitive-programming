#include <climits>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;

int countDigitsInBin(long long n) {
    int res = 0;
    while (n > 0) {
        res++;
        n >>= 1;
    }

    return res;
}

void run() {
    int x;
    long long m;
    cin >> x >> m;
    long long res = 0;

    int xDigits = countDigitsInBin(x);
    int l = pow(2, xDigits);

    for (int y=1; y < l && y <= m; y++) {
        if (x == y) continue;
        int n = x ^ y;
        if (x % n == 0 || y % n == 0) res++;
    }

    /*
    if (m >= l + x) {
        long long c = m - x;
        c = c >> xDigits;
        res += c;
    }
    */

    cout << res << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}