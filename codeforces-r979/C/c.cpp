#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    string b;
    cin >> b;

    char c;
    bool al = false;
    for (int i=0; i < n && !al; i++) {
        char prev = c;
        c = b[i];
        if (i == 0) {
            if (c == '1') al = true;
            continue;
        }
        if (i == n-1) {
            if (c == '1') al = true;
        }

        if (c == '1' && '1' == prev) {
            al = true;
        }
    }

    if (al) cout << "YES";
    else cout << "NO";
    cout << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}