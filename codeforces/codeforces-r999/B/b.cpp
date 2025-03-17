#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int selected = -1;
    int spos = -1;
    for (int i=n-1; i > 0; i--) {
        if (a[i] == a[i-1]) {
            selected = a[i];
            spos = i;
            break;
        }
    }
    if (selected == -1) {
        cout << -1 << "\n";
        return;
    }
    const int tolerance = 2*selected;
    for (int i=n-1; i > 0; i--) {
        if (i == spos || i == spos-1) continue;
        int x = a[i];
        int y = a[i-1];
        int dif = a[i] - a[i-1];
        if (i == spos + 1){
            if (i > 2) dif = a[i] - a[i - 3];
            else break;
            y = a[i - 3];
        }
        if (dif < tolerance) {
            cout << selected << " " << selected << " " << x << " " << y << "\n";
            return;
        }
    }
    cout << -1 << "\n";

}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}