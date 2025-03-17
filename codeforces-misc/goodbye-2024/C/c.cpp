#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n, k;
    cin >> n >> k;

    ll l = 0;
    ll m = 1;
    ll o = 0;
    while (n >= k) {
        ll in = n / 2;
        ll d = 2*in;
        in++;
        d++;

        if (n % 2 == 1) {
            l += m*in + d*((m*(m-1))/2) + (o / 2);
            o += (m) * (m);
            
        }
        //clog << l << endl;
        n /= 2;
        m *= 2;
        o *= 2;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}