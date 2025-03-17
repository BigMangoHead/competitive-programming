#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int d = min(i, n - 1 - i);
        if (a[i] <= 2*(n-1-d)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1;
        run();
    }
}