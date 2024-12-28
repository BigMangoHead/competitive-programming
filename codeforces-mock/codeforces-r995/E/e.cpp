#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long
#define tup pair<int, int> // amount, +1 / -1

void run() {
    int k, n;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    vector<tup> v;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        v.push_back({a[i], 1});
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
        v.push_back({b[i], -1});
    }

    auto comp = [&](tup & a, tup & b) {
        return a.first < b.first;
    };

    sort(v.begin(), v.end(), comp);
    ll c = n;
    int neg = 0;
    ll best = -1;
    for (int i=0; i < v.size(); i++) {
        tup & e = v[i];

        if (neg <= k && (i == 0 || v[i-1].first != v[i].first)) best = max(best, ((ll) e.first)*c);
        if (e.second == 1) {
            neg++;
        } else {
            neg--;
            c--;
        }
    }

    cout << best << endl;

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