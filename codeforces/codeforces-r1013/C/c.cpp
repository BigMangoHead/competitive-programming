#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }
    for (int i=0; i < n; i++) {
        if (2*i+1 == n) {
            cout << n << ' ';
            continue;
        }
        cout << (2*i+1) % n << ' ';
    }
    cout << "\n";
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
