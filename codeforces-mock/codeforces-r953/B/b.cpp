#include <bits/stdc++.h>
using namespace std;

void run() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long best = b-a;

    if (best > n) best = n;
    if (best < 0) best = 0;
    long long k = best;
    long long res = a*n - a*k + b*k  +k - (k*(k+1))/2;
    cout << res << endl;
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