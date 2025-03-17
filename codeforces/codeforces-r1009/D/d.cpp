#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
#define int ll
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    map<int, int> y;
    for (int i=0; i < n; i++) {
        cin >> x[i];
    }
    for (int i=0; i < n; i++) {
        int a;
        cin >> a;
        for (int j=x[i] - a; j <= x[i] + a; j++) {
            int prev = -1;
            auto bef = y.find(j);
            if (bef != y.end()) {
                prev = (*bef).second;
            }

            int ne = sqrt(a*a - (j - x[i])*(j - x[i]));
            y[j] = max(prev, ne);
        }
    }

    long long res = 0;
    for (auto& v : y) {
        res += 2*v.second + 1;
    }
    cout << res << endl;
}

signed main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
