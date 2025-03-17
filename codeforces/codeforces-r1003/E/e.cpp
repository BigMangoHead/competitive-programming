#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    char big = (n > m) ? '0' : '1';
    char small = (n > m) ? '1' : '0';
    if (n < m) swap(n, m);
    if (n - m > k || k > n) {
        cout << -1 << "\n";
        return;
    }

    string res(k, big);
    n -= k;
    while (n > 0) {
        res += small;
        res += big;
        n--;
        m--;
    }
    res += string(m, small);

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