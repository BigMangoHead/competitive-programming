#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    long long n, b, c;
    cin >> n >> b >> c;
    long long moves = 0;
    if (b == 0) {
        if (n > c + 2) {
            moves = -1;
        } else if (n == c+2) {
            moves = n-1;
        } else if (n == c+1) {
            moves = n-1;
        } else {
            moves = n;
        }
    } else if (b == 1) {
        moves = min(n, c);
    } else {
        long long m = n-1; // max number
        m -= c;
        long long safeCount;
        if (m >= 0) {
            m -= m % b;
            if (m >= 0) safeCount = 1 + (m / b);
            else safeCount = 0;
        } else {
            safeCount = 0;
        }
        
        moves = n - safeCount;
    }

    cout << moves << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}