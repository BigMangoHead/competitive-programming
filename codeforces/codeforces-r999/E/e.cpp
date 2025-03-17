#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long

void run() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, map<ll, int>> efficiency;
    vector<ll> a(n);
    ll initsum = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        initsum += a[i];
    }
    vector<ll> b(m);
    for (int i=0; i < m; i++) {
        cin >> b[i];
    }

    for (auto & e : a) {
        for (auto & mov : b) {
            efficiency[e & (!mov)][e]++;
        }
    }

    ll decrease = 0;
    while (k > 0) {
        int nexteff = (efficiency.rbegin())->first;
        auto &cureffmap = efficiency[nexteff];
        if (cureffmap.size() == 0) efficiency.erase(--efficiency.end());
        const auto &iter = cureffmap.begin();
        if (iter->second == 0) {
            cureffmap.erase(iter);
            continue;
        }
        int startelem = iter->first;
        int newelem = startelem & !nexteff;

        // int &currcount = iter->second;
        // currcount--;
        // if (currcount == 0) {
        //     cureffmap.erase(iter);
        //     if (cureffmap.size() == 0) {
        //         efficiency.erase(--efficiency.end());
        //     }
        // }

        decrease += nexteff;

        for (auto & mov : b) {
            efficiency[startelem & (!mov)][startelem]--;
            efficiency[newelem & (!mov)][startelem]++;
        }

        k--;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}