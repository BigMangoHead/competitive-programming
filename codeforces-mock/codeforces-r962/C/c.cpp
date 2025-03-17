#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, q;
    cin >> n >> q;
    vector<array<int, 26>> psa(n);
    for (int i=0; i < n; i++) {
        char c;
        cin >> c;
        if (i > 0) psa[i] = psa[i-1];
        psa[i][c - 'a']++;
    }

    vector<array<int, 26>> psb(n);
    for (int i=0; i < n; i++) {
        char c;
        cin >> c;
        if (i > 0) psb[i] = psb[i-1];
        psb[i][c - 'a']++;
    }

    for (int i=0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int d = 0;
        for (int j=0; j < 26; j++) {
            int da = 0, db = 0;
            db += psb[r-1][j];
            da += psa[r-1][j];
            if (l > 1) da -= psa[l-2][j];
            if (l > 1) db -= psb[l-2][j];
            d += abs(db - da);
        }
        cout << (d + 1) / 2 << endl;
    }
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