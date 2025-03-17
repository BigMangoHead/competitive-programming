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
        value = 1;
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

vector<ModInt> getInverses(int u) {
    vector<ModInt> inverses;
    inverses.push_back(0);
    for (int x=1; x <= u; x++) {
        inverses.push_back(inv(ModInt(x)));
    }
    return inverses;
}

const static vector<int> primesS = getPrimes(400);
const static vector<ModInt> inverses = getInverses(20);

void run() {
    int k, n;
    cin >> k >> n;

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

    auto funcg = [&](ll x) {
        ModInt res(1);
        map<int, int> fac = factorize(x);

        for (auto& e : fac) {
            int val = n - 1 + e.second;
            int den = e.second;
            while (den > 0) {
                res *= val;
                val--;
                res *= inverses[den];
                den--;
            }
        }

        return res;
    };

    vector<ModInt> gdp(2*k+1);
    for (int i=1; i <= 2*k; i++) {
        gdp[i] = funcg(i);
    }

    vector<ModInt> f(k+1);
    f[0] = 0;

    vector<vector<int>> facs(2*k+1);

    for (int d=1; d <= 2*k; d++) {
        for (int m=1; m*d <= 2*k; m++) {
            facs[d*m].push_back(d);
        }
    }

    for (int x=1; x <= k; x++) {
        ModInt res(-1);
        for (auto& fac : facs[2*x]) {
            res += gdp[fac];
            if (fac < x) {
                res = res + f[fac]*-1;
            }
        }
        f[x] = res;
    }

    for (int i=1; i <= k; i++) {
        cout << f[i].value << "\n";
    }

    
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}