#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, c;
    cin >> n >> c;

    vector<long long> fans(n);
    vector<long long> sum(n);
    for (int i=0; i < n; i++) {
        cin >> fans[i];
    }
    fans[0] += c;
    sum[0] = fans[0];
    for (int i=1; i < n; i++) {
        sum[i] = sum[i-1] + fans[i];
    }
    long long ma = -1;
    int maPos = 0;
    vector<long long> maxAfter(n);
    for (int i=n-1; i >= 0; i--) {
        maxAfter[i] = ma;
        if (fans[i] >= ma) {
            maPos = i;
        }
        ma = max(ma, fans[i]);
    }

    vector<int> res(n);
    for (int i=0; i < n; i++) {
        if (i == maPos) {
            res[i] = 0;
        } else if (sum[i] >= maxAfter[i]) {
            res[i] = i;
        } else {
            res[i] = i+1;
        }
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}