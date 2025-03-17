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
