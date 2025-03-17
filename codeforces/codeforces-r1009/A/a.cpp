#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (((a == b) && (b == c) && (c == d)) ? "YES" : "NO") << endl;

    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
