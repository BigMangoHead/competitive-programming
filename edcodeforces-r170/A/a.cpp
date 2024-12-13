#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    string s1, s2;
    cin >> s1 >> s2;

    int shared = 0;
    for (int i=0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) {
            shared ++;
        } else {
            break;
        }
    }
    if (shared == 0) shared++;
    cout << s1.size() + s2.size() - shared + 1 << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}