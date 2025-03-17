#include <iostream>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    cout << max(n, m) + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        // clog << "Case " << i+1;
        run();
    } 
}