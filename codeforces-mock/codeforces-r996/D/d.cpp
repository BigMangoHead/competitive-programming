#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int k, n, l;
    cin >> k >> n >> l;

    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> u(n, 0);

    int t=a[0];
    u[0] = 1;
    int pos=k;
    while (pos < l) {
        
    }
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