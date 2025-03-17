#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }

    int imp = -1;
    for (int i=0; i < n; i++) {
        if (a[i] < b[i]) {
            if (imp != -1) {
                cout << "NO" << endl;
                return;
            }
            imp = i;
        }
    }
    if (imp == -1) {
        cout << "YES" << endl;
        return;
    }

    int mi = INT_MAX;
    for (int i=0; i < n; i++) {
        if (i != imp) mi = min(mi, a[i] - b[i]);
    }

    if (mi >= b[imp] - a[imp]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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