#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> primeCount(n+1, 1); //starts as isPrime

    for (int a=2; a*a <= n; a++) {
        for (int b=a*a; b <= n; b += a) {
            primeCount[b] = 0;
        }
    }
    int count = 0;
    for (int i=2; i < n+1; i++) {
        if (primeCount[i] == 1) count++;
        primeCount[i] = count;
    }
    primeCount[1] = 0;
    ll res = 0;
    for (int a=1; a < n; a++) {
        res += primeCount[n / a];
    }
    cout << res << "\n";
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
