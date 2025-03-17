#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long


template <int64_t mod = 998244353>
struct ModInt{
    int64_t p;

    ModInt() : p(0){}
    ModInt(int64_t x){p = x >= 0 ? x % mod : x + (-x + mod - 1) / mod * mod;}

    ModInt& operator+=(const ModInt& y){p = p + *y - ((p + *y) >= mod ? mod : 0); return *this;}
    ModInt& operator-=(const ModInt& y){p = p - *y + (p - *y < 0 ? mod : 0); return *this;}
    ModInt& operator*=(const ModInt& y){p = (p * *y) % mod; return *this;}
    ModInt& operator%=(const ModInt& y){if(y)p %= *y; return *this;}

    ModInt operator+(const ModInt& y) const{ModInt x = *this; return x += y;}
    ModInt operator-(const ModInt& y) const{ModInt x = *this; return x -= y;}
    ModInt operator*(const ModInt& y) const{ModInt x = *this; return x *= y;}
    ModInt operator%(const ModInt& y) const{ModInt x = *this; return x %= y;}

    friend ostream& operator<<(ostream& stream, const ModInt<mod>& x){
        stream << *x;
        return stream;
    }

    friend ostream& operator>>(ostream& stream, const ModInt<mod>& x){
        stream >> *x;
        return stream;
    }

    ModInt& operator++(){p = (p + 1) % mod; return *this;}
    ModInt& operator--(){p = (p - 1 + mod) % mod; return *this;}

    bool operator==(const ModInt& y) const{return p == *y;}
    bool operator!=(const ModInt& y) const{return p != *y;}

    const int64_t& operator*() const{return p;}
    int64_t& operator*(){return p;}

};

using mint = ModInt<>;

// Copied from geeksforgeeks.org
int modInverse(int A, int M) {
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

void run() {
    mint p = 1;
    int n, ql;
    cin >> n >> ql;
    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int, int>> q(ql);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }
    for (int i=0; i < ql; i++) {
        int o;
        int x;
        cin >> o >> x;
        q[i] = {o, x};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0; i < n; i++) {
        p *= min(a[i], b[i]);
    }

    for (int i=0; i< ql; i++) {
        bool change = false;
        int & av = a[q[i].second - 1];
        int & bv = b[q[i].second - 1];
        if (q[i].first == 1) {
            av++;
            if (av <= bv) {
                change = true;
            }
        } else {
            bv++;
            if (bv <= av) {
                change = true;
            }
        }

        if (change) {
            int old = min(av, bv) - 1;
            p *= modInverse(old, 998244353);
            p *= old+1;
        }
        cout << p << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        clog << "Case " << i+1 << endl;
        run();
    }
}