#include <iostream>
#include <vector>
using namespace std;
#define ll long long

template<int N>
struct PrimeHolder {
    constexpr PrimeHolder() : arr() {
        for (int a = 2; a * a <= N; a++) {
            for (int b = a*a; b <= N; b += a) {
                arr[b] = 1;
            }
        }
        for (int i=1; i <= N; i++) {
            arr[i] = 1 ^ arr[i];
        }
    }
    int arr[N+1] = {};
};

constexpr auto primeHolder = PrimeHolder<200000>();
constexpr auto isPrime = primeHolder.arr;

vector<int> getPrimes() {
    vector<int> primes;
    primes.push_back(2);
    for (int i=3; i < 200000; i += 2) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

const vector<int> primes = getPrimes();
void run() {
    cout << isPrime[100000] << endl;
}

signed main(void) {
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
