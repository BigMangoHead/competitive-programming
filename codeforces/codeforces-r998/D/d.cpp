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

    for (int i=0; i < n-1; i++) {
        int mi = min(a[i], a[i+1]);
        a[i] -= mi;
        a[i+1] -= mi;
    }

    bool works = true;
    for (int i=0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            works = false;
            break;
        }
    }
    cout << (works ? "YES" : "NO") << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}