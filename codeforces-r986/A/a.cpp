#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int xpos = 0;
    int ypos = 0;
    bool success = false;
    for (int i=0; i < 20; i++) {
        for (int j=0; j < n; j++) {
            if (s[j] == 'N') ypos++;
            else if (s[j] == 'W') xpos--;
            else if (s[j] == 'E') xpos++;
            else if (s[j] == 'S') ypos--;

            if (xpos == a && ypos == b) {
                success = true;
                break;
            }
        }
        if (success) break;
    }

    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}