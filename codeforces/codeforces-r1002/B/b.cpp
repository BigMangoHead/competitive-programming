#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    if (k == n) {
        int next = 1;
        for (int i=0; i < n; i++) {
            if (a[2*i+1] == next) {
                next++;
            } else {
                cout << next << "\n";
                return;
            }
        }
        cout << next << "\n";
        return;
    }

    int res;
    if (a[0] == 1) {
        int oc = 0;
        int i = 0;
        while (i < n && a[i] == 1) {
            oc++;
            i++;
        }

        if (oc == 1 || oc == 2) res = 1;
        else if (n-k > oc-2) res = 1;
        else res = 2;
    } else {
        int oc = 0;
        int i = 1;
        while (i < n && a[i] == 1) {
            oc++;
            i++;
        }
        if (oc == 0 || oc == 1) res = 1;
        else if (n - k > oc-1) res = 1;
        else res = 2;
    }

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