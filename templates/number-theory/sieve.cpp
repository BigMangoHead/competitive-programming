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

constexpr auto primeHolder = PrimeHolder<100000>(); // Size of sieve
const auto isPrime = &primeHolder.arr;
