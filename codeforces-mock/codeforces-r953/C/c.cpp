#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void run() {
    long long n, kinput;
    cin >> n >> kinput;
    if (kinput % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    long long kp = kinput / 2;
    //if (kp > (n*(n+1))/2) cout << "NO" << endl;

    long long mostFull = 0;

    long long rem = kp;
    int dif = n+1;
    int count = 0;
    while (rem > 0) {
        if (dif <= 0) {
            cout << "NO" << endl;
            return;
        }
        dif -= 2;
        rem -= dif;
        count++;
    }
    if (rem != 0) {
        rem += dif;
        count--;
    }

    vector<int> res(n);
    for (int i=0; i < n-count; i++) {
        if (i < count) {
            res[i] = n-i;
            res[n-1-i] = i+1;
        } else {
            res[i] = i+1;
        }
    }

    swap(res[count], res[count+rem]);
    cout << "YES" << endl;
    for (auto & e : res) {
        cout << e << ' ';
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