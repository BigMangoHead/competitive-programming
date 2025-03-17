#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ll long long

static vector<ll> genSquares() {
    ll n = 1;
    vector<ll> res;
    while (n <= 500000) {
        res.push_back(n*n);
        n++;
    }
    return res;
}


static vector<ll> squares = genSquares();

bool isSquare(ll n) {
    return binary_search(squares.begin(), squares.end(), n);
}

void run() {
    ll n;
    cin >> n;
    if (isSquare((n*(n+1))/2)) {
        cout << -1 << endl;
        return;
    }

    ll sum = 0;
    for (ll i=1; i <= n; i++) {
        sum += i;
        if (isSquare(sum)) {
            cout << i + 1 << ' ' << i << ' ';
            sum += i+1;
            i++;
        } else {
            cout << i << ' ';
        }
    }
    cout << "\n";
}

signed main(void) {
    ll n;
    cin >> n;
    for (ll i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
