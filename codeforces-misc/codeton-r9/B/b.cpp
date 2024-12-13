#include <climits>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    string s;
    cin >> s;
    const int k = s.size();

    char pp = s[0];
    char p = s[1];
    if (pp == p) {
        cout << s.substr(0, 2) << endl;
        return;
    }
    for (int i=2; i < k; i++) {
        char c = s[i];
        if (c == p) {
            cout << s.substr(i-1, 2) << endl;
            return;
        } else if (c != pp) {
            cout << s.substr(i-2, 3) << endl;
            return;
        } else {
            pp = p;
            p = c;
        }
    }
    cout << -1 << endl; 
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}