#include <iostream>
using namespace std;

void run() {
    int n;
    cin >> n;
    int ma = 0;
    int best = 0;
    for (int x=2; x <= n; x++) {
        int sum = 0;
        for (int k=1; k*x <= n; k++) {
            sum += k*x;
        }
        if (sum > ma) {
            best = x;
        }
        ma = max(ma, sum);
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