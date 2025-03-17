#include <iostream>
#include <vector>
using namespace std;
#define ll long long

static const int modulo = 998244353;

void run() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    ll ltr = 1;
    ll lli = 1;
    if (a[1] != 0) {
        ltr = 0;
    }

    for (int i=2; i <= n; i++) {
        ll nlli = 0;
        ll nltr = 0;
        // Case 1 - New person is a liar
        nlli += ltr;

        // Case 2 New person is a truth-speaker
        if (a[i] == a[i-1]) {
            nltr += ltr;
        }
        if (a[i] == a[i-2] + 1) {
            nltr += lli;
        }

        ltr = nltr % modulo;
        lli = nlli % modulo;
    }

    cout << (lli + ltr) % modulo << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}