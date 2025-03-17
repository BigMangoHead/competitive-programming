#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

const static int modulo = 998244353;

class ModInt {
    public: 
    long long value;
    ModInt() {
        value = 0;
    }

    ModInt(ll x) {
        value = x % modulo;
        if (value < 0) value += modulo;
    }

    ModInt operator+(ModInt const& x) {
        return ModInt(this->value + x.value);
    }

    ModInt operator*(ModInt const& x) {
        return ModInt(this->value * x.value);
    }

    void operator+=(ModInt const& x) {
        this->value = (this->value + x.value) % modulo;
    }

    void operator*=(ModInt const& x) {
        this->value = (this->value * x.value) % modulo;
    }

    ModInt operator+(ll const& x) {
        return ModInt(this->value + x);
    }

    ModInt operator*(ll const& x) {
        return ModInt(this->value * x);
    }

    ModInt pow(long long e) {
        e--;
        ModInt res(this->value);
        ModInt cur(this->value);
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

ModInt inv(ModInt x) {
    return x.pow(modulo-2);
}

vector<int> getPrimes(int u) {
    vector<int> primes;
    for (int x=2; x < u; x++) {
        bool works = true;
        for (int y=2; y < x; y++) {
            if (x % y == 0) works = false;
        }
        if (works) primes.push_back(x);
    }
    return primes;
}

const static vector<int> primesS = getPrimes(400);

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int m;
    cin >> m;
    ModInt sum[100010] = {};
    ModInt sum2[100010] = {};
    ll count[100010] = {};

    auto factorize = [&](int x) {
        map<int, int> fac;
        for (auto& p : primesS) {
            while (x % p == 0) {
                x /= p;
                fac[p]++;
            }
        }
        if (x > 1) fac[x]++;
        return fac;
    };

    vector<int> facs[100020];

    for (int d=1; d <= 100010; d++) {
        for (int m=1; m*d <= 100010; m++) {
            facs[d*m].push_back(d);
        }
    }

    for (int i=0; i < m; i++) {
        ll x;
        cin >> x;
        ll y;
        cin >> y;
        ModInt freq(y);

        for (auto& v : facs[x]) {
            sum[v] += freq*x;
            sum2[v] += freq*(x*x);
            count[v] += y;
        } 
    }

    ModInt res;
    map<int, ModInt> precomp;
    precomp[-1] = inv(ModInt(2));
    for (int i=1; i <= 100000; i++) {
        ll c = count[i];
        if (c < 2) continue;
        int s = 0;
        for (auto& [k, v] : factorize(i)) {
            s++;
            if (v > 1) s = -10000;
        }
        if (s < 0) continue;
        if (c != 2 && precomp.find(c - 3) == precomp.end()) {
            precomp[c - 3] = ModInt(2).pow(c-3);
        }
        
        ModInt mobius(1);
        if (s % 2 == 1) mobius = ModInt(-1);
        res += mobius * precomp[c-3] * (sum2[i]*(c-2) + (sum[i]*sum[i])*c);
    }
    cout << res.value << endl;
}