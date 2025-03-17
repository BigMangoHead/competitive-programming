#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n+1);
    vector<int> f(2*n+1, 0);
    vector<int> s(2*n+1, 0);
    a.push_back({0, 0});
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        a[i+1] = {x, y};
        if (x == y) {
            f[x]++;
        }
    }

    int sum = 0;
    for (int i=1; i < 2*n+1; i++) {
        if (f[i] >= 1) sum++;
        s[i] = sum;
    }

    for (int i=1; i < n+1; i++) {
        if (a[i].first == a[i].second) {
            if (f[a[i].first] > 1) {
                cout << 0;
            } else {
                cout << 1;
            }
        } else {
            if (s[a[i].second] - s[a[i].first-1] == a[i].second - a[i].first + 1) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
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