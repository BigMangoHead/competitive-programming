#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;
    int zeros = 0, ones = 0;
    for (int i=0; i < n; i++) {
        if (s[i] == '0') zeros++;
        else ones++;
    }

    bool works = true;
    for (int i=0; i < n-1; i++) {
        if (zeros <= 0 || ones <= 0) {
            works = false;
            break;
        }

        if (r[i] == '0') ones--;
        else zeros--;
    }

    if (works) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}