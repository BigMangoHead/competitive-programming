#include <iostream>
using namespace std;
#define ll long long

void run() {
    ll n;
    cin >> n;
    ll c = 1;
    while (n >= 4*c) {
        n /= 4;
        n*= 2;
        c*= 2;
    }
    cout << c << endl;
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