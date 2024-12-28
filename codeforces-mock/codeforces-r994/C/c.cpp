#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    if (n % 2 == 0) {
        for (int i=0; i < n; i++) {
            a[i] = i % 2;
        }
        if (x % 2 == y % 2) {
            a[x-1] = 2;
        }
    } else {
        a[x-1] = 2;
        for (int i=1; i < n; i++) {
            a[(x - 1 + i) % n] = i % 2;
        }
    }

    for (int i=0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


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