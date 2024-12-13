#include <vector>
#include <iostream>
using namespace std;

long long pluscost(long long c, long long x) {
    if (x > 0LL) {
        return 0LL;
    } else {
        return c*(-x + 1LL);
    }
}

long long minuscost(long long c, long long x) {
    if (x < 0LL) {
        return 0LL;
    } else {
        return c*(x + 1LL);
    }
}

int main(void) {
    long long n, c, r;

    cin >> n >> c >> r;

    vector<long long> seq(n);
    vector<long long> plus(n+1);
    vector<long long> minus(n+1);

    for (int i=0; i < n; i++) {
        long long x;
        cin >> x;
        seq[i] = x;
    }

    plus[0] = 0LL;
    minus[0] = 0LL;
    for (int i=0; i<n; i++) {
        plus[i+1] = min(minus[i]+pluscost(c, seq[i]), plus[i]+r);
        minus[i+1] = min(plus[i]+minuscost(c, seq[i]), minus[i]+r);
    }

    cout << min(plus[n], minus[n]) << endl;

    // remember to endl

    return 0;
}