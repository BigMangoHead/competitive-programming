#include <iostream>
#include <set>
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

using mint = ModInt<1000000007>;

void run() {
    ll n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int>> a;
    int wc = 0;
    for (int i=0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (min(x, y) == 1 || x == n || y == m) {
            a.insert({x, y});
            if (z == 1) wc++;
        }
    }

    ll mult;
    if (n + m > k) mult = -1;
    else {
        bool found = false;
        for (int x=1; x < n; x++) {
            if (a.find({x, 1}) == a.end() || a.find({x, n}) == a.end()) {
                found = true;
                break;
            }
        }
        for (int y=1; y < m; y++) {
            if (a.find({1, y}) == a.end() || a.find({n, y}) == a.end()) {
                found = true;
                break;
            }
        }
        if (found) {
            mult = -1;
        } else {
            if (wc % 2 == 1) mult = 0;
            else mult = 1;
        }
    }

    if (mult == 0 || n*m == k) {
        cout << 0 << endl;
        return;
    } 
    int exp = n*m - k;
    if (mult == -1) exp--;
    cout << mint(2).pow(exp).val << endl;
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
