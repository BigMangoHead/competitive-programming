#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long

bool checkN(ll n) {
    string x = to_string(n);
    for (auto& c : x) if (c == '7') return true;
    return false;
}

void run() {
    ll n;
    cin >> n;
    if (checkN(n)) {
        cout << "0\n";
        return;
    }
    ll best = 20;
    for (int s=1; s <= 10; s++) {
        ll add = pow(10, s) - 1;
        ll nc = n;
        ll x = 0;
        while (x <= 10) {
            nc += add;
            x++;
            if (checkN(nc)) break;
        }
        //clog << nc << ' ' << x << endl;
        best = min(best, x);
    }
    cout << best << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
