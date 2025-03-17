#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void works() {
    cout << "YES" << endl;
}

void run() {
    int n;
    cin >> n;
    pmr::vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    for (int i=1; i < n; i++) {
        if (a[i] > a[i-1]) {
            if (a[i] / a[i-1] == 1) {
                works();
                return;
            }
        } else if (a[i] <= a[i-1]) {
            if (a[i-1] / a[i] == 1) {
                works();
                return;
            }
        }
    }
    cout << "NO" << endl;
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