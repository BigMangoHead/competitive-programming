#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n, x;
    ll k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    
    ll maxleft = 0; // this will be negative
    ll maxright = 0;
    ll change = 0;
    ll timetozero = -1;
    ll pos = 0;
    ll cm = 0;
    for (auto& c : s) {
        cm++;
        if (c == 'R') pos++;
        else pos--;

        if (timetozero == -1 && pos == 0) timetozero = cm;
        maxleft = min(pos, maxleft);
        maxright = max(pos, maxright);
    }
    change = pos;

    ll res = 0;
    if ((x > 0 && x + maxleft <= 0) || (x < 0 && x + maxright >= 0) || x == 0) {
        //cout << "test" << endl;
    } else {
        ll goal;
        if (x > 0) {
            goal = maxleft*-1;
            if (change >= 0) {
                cout << "0\n"; return;
            }
            change *= -1;
            k -= ((x - goal + change - 1) / change) * n;
            x -= ((x - goal + change - 1) / change)*change;
        } else {
            x *= -1;
            goal = maxright;
            if (change <= 0) {
                cout << "0\n"; return;
            }
            k -= ((x - goal + change - 1) / change) * n;
            x -= ((x - goal + change - 1) / change) * change;
            x*= -1;
        }
    }

    for (auto& c : s) {
        if (x == 0) break;
        k--;
        if (c == 'R') x++;
        else x--;
    }
    if (k < 0) {
        cout << "0\n";
        return;
    }
    res++;
    if (timetozero != -1) res += (k / timetozero);

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