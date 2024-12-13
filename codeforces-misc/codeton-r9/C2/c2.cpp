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
        int n = x ^ y;
        if (n % x == 0 || n % y == 0) res++;
    }

    if (m >= l) {
        long long c = m / x;
        c--; // one counted in loop above

        long long needed = l - 1 - x;
        if (needed <= m % l) {
            c++;
        }

        res += c;
    }

    

    cout << res << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}