#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int tc = 0;
    int ic = 0;
    for (int i=0; i < n; i++) {
        char x;
        cin >> x;
        if (x == 'T') {
            a[i] = 0;
            tc++;
        }
        else if (x == 'I') {
            a[i] = 1;
            ic++;
        }
        else a[i] = 2;
    }
    int lc = n - ic - tc;
    int ma;
    int mi;
    int l;
    if (tc >= ic && tc >= lc) {
        ma = 0;
        if (ic >= lc) {
            mi = 1;
            l = 2;
        } else {
            mi = 2;
            l = 1;
        }
    } else if (ic >= tc && ic >= lc) {
        ma = 1;
        if (tc >= lc) {
            mi = 0;
            l = 2;
        } else {
            mi = 2;
            l = 0;
        }
    } else {
        ma = 2;
        if (tc >= ic) {
            mi = 0;
            l = 1;
        } else {
            mi = 1;
            l = 0;
        }
    }

    int mac = count(a.begin(), a.end(), ma);
    int mic = count(a.begin(), a.end(), mi);
    lc = n - mac - mic; // now is low count
    int ni = n;

    vector<int> moves;

    int pos = 0;
    while (pos < n-1) {
        if (a[pos] != a[pos+1] && (a[pos] == ma || a[pos+1] == ma)) break;
        pos++;
    }
    if (pos >= n-1) {
        cout << -1 << "\n";
        return;
    }
    while (mac > mic) {
        mic++;
        lc++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != ma) pos++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != ma) pos++;
        n += 2;
    }
    
    for (int i=0; i < n-1 && lc < mic; i++) {
        if ((3 ^ a[i] ^ a[i+1]) == l) {
            lc++;
            n++;
            a.insert(a.begin() + i + 1, l);
            moves.push_back(i+1);
        }
    }

    int count = mic - lc;
    pos = 0;
    while (pos < n-1) {
        if (a[pos] != a[pos+1] && ((3 ^ a[pos] ^ a[pos+1]) == mi)) break;
        pos++;
    }
    for (int i=0; i < count; i++) {
        mic++;
        lc++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != ma) pos++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != ma) pos++;
        n += 2;
    }

    pos = 0;
    while (pos < n-1) {
        if (a[pos] != a[pos+1] && ((3 ^ a[pos] ^ a[pos+1]) == ma)) break;
        pos++;
    }
    for (int i=0; i < count; i++) {
        mic++;
        lc++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != mi) pos++;
        moves.push_back(pos+1);
        a.insert(a.begin() + pos + 1, 3 ^ a[pos] ^ a[pos+1]);
        if (a[pos] != mi) pos++;
        n += 2;
    }
#ifdef LOCAL
    for (auto& v : a) {
        if (v == 0) clog << "T";
        else if (v == 1) clog << "I";
        else clog << "L";
    }
    clog << endl;
#endif


    
    if (moves.size() > 2*ni) {
        cout << -1 << "\n";
        return;
    }

    cout << moves.size() << "\n";
    for (auto& m : moves) {
        cout << m << "\n";
    }
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
