#include <cmath>
#include <iostream>
using namespace std;

const static int mod = pow(10, 9) + 7;

long long exp(long long x, long long pow) {
    long long res = 1;
    while (pow >= 2) {
        if (pow % 2 == 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        pow /= 2;
    }
    if (pow == 1) {
        res *= x;
        res %= mod;
    }
    return res;
}

void run() {
    long long l, r, k;
    cin >> l >> r >> k;

    if (k >= 10) {
        cout << 0 << endl;
        return;
    }

    int ops = (9 / k) + 1;

    long long res = exp(ops, r);
    long long res2 = exp(ops, l);

    res = (mod + res - res2) % mod;

    cout << res << endl;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}