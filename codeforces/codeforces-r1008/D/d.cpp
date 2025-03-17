#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    ll n;
    cin >> n;
    vector<ll> bonus[2];
    vector<vector<ll>> ops(n);

    for (int i=0; i < n; i++) {
        char o1, o2;
        ll x, y;
        cin >> o1 >> x >> o2 >> y;
        ops[i] = {(o1 == '+' ? 0 : 1), x, (o2 == '+' ? 0 : 1), y};
        if (o1 == 'x') bonus[0].push_back(x);
        else bonus[0].push_back(1);
        if (o2 == 'x') bonus[1].push_back(y);
        else bonus[1].push_back(1);
    }

    int choice = 0;
    vector<int> ch(n);
    for (int i=n-1; i >= 0; i--) {
        ch[i] = choice;
        if (bonus[0][i] > bonus[1][i]) choice = 0;
        else if (bonus[1][i] > bonus[0][i]) choice = 1;
    }

    ll l = 1;
    ll r = 1;

    for (int i=0; i < n; i++) {
        vector<ll> curop = ops[i];
        ll toadd = 0;
        if (curop[0] == 0) toadd += curop[1];
        else toadd += (curop[1]-1)*l;
        if (curop[2] == 0) toadd += curop[3];
        else toadd += (curop[3]-1)*r;

        if (ch[i] == 0) l += toadd;
        else r += toadd;

        //clog << l << ' ' << r << endl;

        //int j = i+1;
        //for (; j < n; j++) {
        //    if (ops[j][0] == 1) break;
        //    if (ops[j][2] == 1) break;
        //}
        //if (j == n) l += toadd; // doesn't matter in this case
        //else {
        //    vector<ll> multcase = ops[j];
        //    if (multcase[0] == 1 && multcase[2] == 1) {
        //        if (multcase[1] == multcase[3]) {
        //            if (bonus[0][i] >= bonus[1][i]) l += toadd;
        //            else r += toadd;
        //        } else {
        //            if (multcase[1] > multcase[3]) l += toadd;
        //            else r += toadd;
        //        }
        //    } else if (multcase[0] == 1) {
        //        l += toadd;
        //    } else {
        //        r += toadd;
        //    }
        //}

    }

    cout << l + r << endl;
}

int main(void) {
    ll n;
    cin >> n;
    for (ll i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
