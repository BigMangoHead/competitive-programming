#include <iostream>
#include <vector>
using namespace std;
#define ll long long

template <int modulo>
struct ModInt {
    long long val;

    ModInt() {
        val = 0;
    }

    ModInt(long long x) {
        val = x % modulo;
        if (val < 0) val += modulo;
    }

    ModInt operator+(ModInt const& x) {
        return ModInt(this->val + x.val);
    }

    ModInt operator*(ModInt const& x) {
        return ModInt(this->val * x.val);
    }

    void operator+=(ModInt const& x) {
        this->val = (this->val + x.val) % modulo;
    }

    void operator*=(ModInt const& x) {
        this->val = (this->val * x.val) % modulo;
    }

    ModInt operator+(long long const& x) {
        return ModInt(this->val + x);
    }

    ModInt operator*(long long const& x) {
        return ModInt(this->val * x);
    }

    ModInt pow(long long e) {
        e--;
        ModInt res(this->val);
        ModInt cur(this->val);
        while (e > 0) {
            if (e % 2 == 1) {
                res *= cur;
                e--;
            } else {
                cur *= cur;
                e /= 2;
            }
        }
        return res;
    }
};

using mint = ModInt<998244353>;

void run() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        p[i] = x;
    }
    vector<int> q(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        q[i] = x;
    }
    
    vector<mint> val(n);
    val[0] = mint(1);
    for (int i=1; i < n; i++) {
        val[i] = val[i-1]*2;
    }

    int m1 = -1;
    int m1p = -1;
    int m2 = -1;
    int m2p = -1;
    for (int i=0; i < n; i++) {
        if (m1 < p[i]) {
            m1 = p[i];
            m1p = i;
        }
        if (m2 < q[i]) {
            m2 = q[i];
            m2p = i;
        }

        mint v;
        if (m2 > m1) {
            v = val[m2] + val[p[i - m2p]];
        } else if (m2 < m1) {
            v = val[m1] + val[q[i - m1p]];
        } else {
            v = val[m1] + val[max(q[i - m1p], p[i - m2p])];
        }
        cout << v.val << ' ';
    }
    cout << '\n';
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
