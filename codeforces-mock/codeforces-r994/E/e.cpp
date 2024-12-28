#include <climits>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;

    int low = 2;
    int high = n-1;
    cout << "? " << 1 << " " << n/4 << endl;
    cout.flush();
    int q1, q2, q3;
    cin >> q1;
    cout << "? " << n/4 + 1 << " " << n/2 << endl;
    cout.flush();
    cin >> q2;
    cout << "? " << 1 << " " << n/2 << endl;
    cout.flush();
    cin >> q3;

    int inwone;
    int kstate;
    if (q1 != q2) {
        inwone = 1;
        if (q3 == 0) {
            kstate = 1;
        } else {
            kstate = 2;
        }
    } else {
        inwone = 0;
        if (q3 == 0) {
            kstate = 2;
        } else {
            kstate = 1;
        }
    }

    if (kstate == 2) {
        low = n / 2 + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int q;
            if (inwone == 0) {
                cout << "? " << n - mid + 1 << ' ' << n << endl;
                cout.flush();
                cin >> q;
            } else {
                cout << "? 1 " << mid << endl;
                cout.flush();
                cin >> q;
            }
            if (q == 1) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    } else {
        high = n / 2;
        while (low < high) {
            int mid = (low + high) / 2;
            int q;
            if (inwone == 1) {
                cout << "? 1 " << mid << endl;
            } else {
                cout << "? " << n - mid + 1 << ' ' << n << endl;
            }
            cout.flush();
            cin >> q;

            if (q == 1) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    }

    cout << "! " << low << endl;
    cout.flush();


}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i+1 << endl;; 
        run();
    }
}