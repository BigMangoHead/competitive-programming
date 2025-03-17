#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> x(n);
    set<int> x2;
    for (int i=0; i < n; i++) {
        cin >> x[i];
        x2.insert(x[i]);
    }
    if (x2.size() == n) {
        int q, s;
        for (int i=0; i < n; i++) {
            if (x[i] == 1) {
                q = i + 1;
                break;
            }
        }
        for (int i=0; i < n; i++) {
            if (x[i] == n) {
                s = i+1;
                break;
            }
        }
        cout << "? " << q << ' ' << s << endl;
        cout.flush();
        int a, b;
        cin >> a;
        cout << "? " << s << ' ' << q << endl;
        cout.flush();
        cin >> b;
        if (a == b && a >= n-1) cout << "! B"  << endl;
        else cout << "! A"  << endl;
    } else {
        int i = 0;
        for (const int a : x2) {
            if (a != i+1) break;
            i++;
        }
        cout << "? " << i+1 << ' ' << ((i+1) % n)+1 << endl;
        cout.flush();
        int r;
        cin >> r;
        if (r == 0) cout << "! A" << endl;
        else cout << "! B" << endl;
    }
    cout.flush();
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}