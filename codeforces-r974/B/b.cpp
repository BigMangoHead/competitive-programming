#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int a;
    cin >> a;

    for (int i =0; i < a; i++) {
        int lastyear;
        int totalremain;
        cin >> lastyear >> totalremain;

        int parity;
        if (lastyear % 4 == 1 || lastyear % 4 == 2) {
            parity = 1;
        } else {
            parity = 0;
        }

        if (lastyear > totalremain) {
            int dif = lastyear - totalremain;
            if (dif % 4 == 1 || dif % 4 == 2) {
                parity += 1;
            }
        }
        parity %= 2;

        if (parity == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}