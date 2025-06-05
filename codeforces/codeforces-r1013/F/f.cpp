#include <iostream>
#include <vector>
#include <algorithm>
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
        return ModInt(this->val + x.val + modulo);
    }

    ModInt operator*(ModInt const& x) {
        return ModInt(this->val * x.val);
    }

    void operator+=(ModInt const& x) {
        this->val = (this->val + x.val + modulo) % modulo;
    }

    void operator-=(ModInt const& x) {
        this->val = (this->val - x.val + modulo) % modulo;
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
    int m, n, d;
    cin >> n >> m >> d;
    vector<vector<int>> r(n, vector<int>(m));
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            char x;
            cin >> x;
            if (x == 'X') r[i][j] = 1;
            else r[i][j] = 0;
        }
    }
    reverse(r.begin(), r.end());

    vector<vector<mint>> count(n, vector<mint>(m, mint(0)));
    for (int j=0; j < m; j++) {
        if (r[0][j] == 1) count[0][j] = 1;
    }

    for (int i=0; i < n; i++) {
        int wsize = d;
        mint csum(0);

        // Consider shifting along current row
        for (int j=0; j < wsize && j < m; j++) csum += count[i][j];
        vector<mint> pcount = count[i];
        for (int j=0; j < m; j++) {
            if (j + wsize < m) csum += pcount[j+wsize];
            if (j - wsize-1 >= 0) csum -= pcount[j-wsize-1];
            if (r[i][j] == 0) continue;
            count[i][j] = csum;
        }
        //for (auto& v : count[i]) {
        //    clog << v.val << ' ';
        //}
        //clog << endl;
        // Shift up
        csum.val = 0;
        wsize--;
        if (i == n-1) break;
        pcount = count[i];
        for (int j=0; j < wsize && j < m; j++) csum += count[i][j];
        for (int j=0; j < m; j++) {
            if (j + wsize < m) csum += pcount[j+wsize];
            if (j - wsize-1 >= 0) csum -= pcount[j-wsize-1];
            if (r[i+1][j] == 0) continue;
            count[i+1][j] = csum;
        }
    }

    mint res(0);
    for (auto& v : count[n-1]) {
        res += v;
    }
    cout << res.val << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
