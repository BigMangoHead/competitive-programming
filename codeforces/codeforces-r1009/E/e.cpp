#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    int cur[3] = {1, (n+1)/2, n};
    while (true) {
        cout << "? " << cur[0] << ' ' << cur[1] << ' ' << cur[2] << endl;
        cout.flush();
        int x;
        cin >> x;
        if (x == -1) {
            return;
        }
        if (x == 0) break;

        cur[rand() % 3] = x;
    }
    cout << "! " << cur[0] << ' ' << cur[1] << ' ' << cur[2] << endl;
    cout.flush();
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
