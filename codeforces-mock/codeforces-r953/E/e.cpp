#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> & v) {
    for (int i=0; i < v.size(); i++) {
        clog << v[i];
    }
    clog << endl;
}

void run() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> in(n, 0);
    vector<int> e(n, 0);
    vector<int> ll(n, 0);
    vector<int> rr(n, 0);
    vector<int> all(n, 0);

    for (int i=0; i < n; i++) {
        if (s[i] == '1') {
            in[i] = 1;
        }
    }
    
    for (int i=0; i < n; i++) {
        if (s[i] == '1') {
            e[i] = 1;
        }

        if (i > 0 && i < n-1 && t[i-1] == '1' && t[i+1] == '1') {
            e[i] = 1;
        }

        if (i > 1 && i < n-1 && s[i-2] == '0' && t[i+1] == '1') {
            ll[i] = 1;
        }

        if (i > 0 && i < n-2 && s[i+2] == '0' && t[i-1] == '1') {
            rr[i] = 1;
        }

        if (e[i] == 1) {
            ll[i] = 1;
            rr[i] = 1;
        }
    }

    for (int i=1; i < n; i++) {
        all[i] = all[i-1] + (rr[i] | ll[i]);
    }

    //printVector(e);
    //printVector(ll);
    //printVector(rr);
    //printVector(all);
    

    int q;
    cin >> q;
    for (int i=0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r--;
        l--;
        int res = in[r];
        if (r - l == 1) {
            res += in[l];
        } else if (r - l == 2) {
            res += in[l] + e[r-1];
        } else if (r - l >= 3) {
            res += in[l] + rr[l+1] + ll[r-1];
            res += all[r-2] - all[l+1];
        }

        cout << res << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}