#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int nsectionCount = 0;
    int cur = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            a[i] = 1;
        }
        if (a[i] != cur) {
            if (a[i] == 1) nsectionCount++;
            cur = a[i];
        }
    }

    if (nsectionCount == 0) {
        cout << 0 << endl;
    } else if (nsectionCount == 1) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
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