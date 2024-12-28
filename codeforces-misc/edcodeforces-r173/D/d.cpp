#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

int gcd(ll x, ll y) {
    if (x >= y) swap(x, y);
    while (x != 0 && y != 0) {
        y %= x;
        if (y == 0) break;
        x %= y;
    }
    return max(x, y);
}

void run() {
    ll l, r, g;
    cin >> l >> r >> g;

    l = (l-1) / g + 1;
    r /= g;
    ll b = l;
    ll u = r;
    ll dif = 1000000;
    pair<ll, ll> cBest = {-1, -1};

    for (ll x=l; x < min(l + dif, r+1); x++) {
        ll cdif = x - l;
        ll y = r;
        while (cdif < dif && y >= x) {
            if (gcd(x, y) == 1) {
                dif = cdif;
                cBest = {x, y};
            }
            y--;
            cdif++;
        }
    }

    if (cBest.first == -1) g = 1;

    cout << cBest.first*g << " " << cBest.second*g << endl;


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //clog << gcd(3333000, 7890) << endl;

    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}