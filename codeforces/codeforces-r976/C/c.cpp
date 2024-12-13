#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Counts digits base 2, not actually log
int myLog2(long long num) {
    int count = 0;
    while (num > 0) {
        num >>= 1;
        count++;
    }
    return count;
}

void run() {
    long long b, c, goal;
    cin >> b >> c >> goal;
    long long b2, c2;
    b2 = b;
    c2 = c;

    int k = max({myLog2(goal),  myLog2(b), myLog2(c)});

    vector<int> result(k);

    for (int i=0; i < k; i++) {
        int cBit = c2 & 1;
        int bBit = b2 & 1;
        if ((bBit == 0 && cBit == 0)) {
            result[i] = 2;
        } else if ((bBit == 1 && cBit == 1)) {
            result[i] = 3;
        } else if (bBit == 1 && cBit == 0) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
        c2 >>= 1;
        b2 >>= 1;
    }

    long long a = 0;
    for (long long i=0; i<k; i++) {
        int goalBit = goal & 1;
        //cout << "|" << goalBit << " " << result[i] << "|";
        if (result[i] < 2 && result[i] != goalBit) {
            cout << -1 << endl;
            return;
        }

        if (goalBit == 1 && result[i] == 2) {
            a += (1LL << i);
        } else if (goalBit == 0 && result[i] == 3) {
            a += (1LL << i);
        }

        goal >>= 1;
    }

    if (a > (1LL << 61)) {
        cout << -1 << endl;
        return;
    }

    cout << a << endl;
}


int main(void) {
    int testcases;
    cin >> testcases;
    for (int i=0; i < testcases; i++) {
        run();
    }
}