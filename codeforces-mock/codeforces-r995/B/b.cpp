#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n;
    int a, b, c;
    cin >> n >> a >> b >> c;

    ll f = n / (a + b + c);
    
    n -= f*(a + b + c);
    if (n <= 0) {
        cout << f*3 << endl;
        return;
    }

    n -= a;
    if (n <= 0) {
        cout << f*3 + 1 << endl;
        return;
    }

    n -= b;
    if (n <= 0) {
        cout << f*3 + 2 << endl;
        return;
    }

    cout << f*3 + 3 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}