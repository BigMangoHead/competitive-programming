#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> w(n);
    int prev[200010][30];
    int cur[30];
    for (int i=0; i < 30; i++) cur[i] = -1;

    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        w[i] = x;
        int d = 0;
        while (x > 0) {
            if (x & 1) cur[d] = i;
            x >>= 1;
            d++;
        }
        for (int j=0; j < 30; j++) {
            prev[i][j] = cur[j];
        }
    }

    for (; q > 0; q--) {
        int x;
        cin >> x;
        int curpos = n-1;
        while (x > 0) {
            int d = 0;
            int xc = x;
            while (xc > 0) {
                xc >>= 1;
                d++;
            }
            d--;
            curpos = prev[curpos][d];
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}