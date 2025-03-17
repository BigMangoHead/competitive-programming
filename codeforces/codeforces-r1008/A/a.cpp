#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, x;
    cin >> n >> x;
    ll sum = 0;
    for (int i=0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum % n != 0) {
        cout << "NO" << endl;
        return;
    }
    if (sum / n == x) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
