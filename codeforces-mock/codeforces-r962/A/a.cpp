#include <bits/stdc++.h>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    cout << (n - 1) / 4 + 1;
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