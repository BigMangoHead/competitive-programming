#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define ll long long

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

const static vector<int> primesS = getPrimes(1000);

void run() {
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

    int n;
    cin >> n;
    map<int, ll> ap;
    ll primecount = 0;
    map<int, int> asp;
    map<int, ll> aspC;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        map<int, int> f = factorize(x);
        int sum = 0;
        for (auto& v : f) {
            sum += v.second;
        }
        if (sum == 1) {
            ap[x]++;
            primecount++;
        } else if (sum == 2) {
            for (auto& v : f) {
                asp[v.first]++;
            }
            aspC[x]++;
        }
    }

    ll primestogether = 0;
    ll res = 0;
    for (auto& v : ap) {
        //cout << "RES " << v.first << ' ' << v.second << "\n";
        primestogether += v.second * (primecount - v.second);
        if (asp.count(v.first)) {
            res += asp[v.first] * v.second;
            //cout << "NEWRES " << res << endl;
        }
    }

    for (auto& v : aspC) {
        res += (v.second * (v.second + 1))/2;
    }

    primestogether /= 2;
    res += primestogether;

    cout << res << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}