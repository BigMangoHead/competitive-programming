#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int check(const char & a, const char & b, const char & c) {
    if (a == 'A' && b == 'A') {
        return 1;
    } else if (a == 'A' && c == 'A') {
        return 1;
    } else if (b == 'A' && c == 'A') {
        return 1;
    } else {
        return 0;
    }
}

void run() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 += "JJJ";
    s2 += "JJJ";

    vector<int> above(n / 3 + 1, 0), below(n / 3 + 1, 0), equiv(n / 3 + 1, 0);
    for (int i=0; i < n / 3; i++) {
        equiv[i + 1] = equiv[i] + check(s1[3*i], s1[3*i + 1], s1[3*i + 2]) + check(s2[3*i], s2[3*i + 1], s2[3*i + 2]);

        above[i] = max(above[i], equiv[i] + check(s1[3*i], s1[3*i + 1], s2[3*i]));
        below[i] = max(below[i], equiv[i] + check(s1[3*i], s2[3*i], s2[3*i + 1]));

        equiv[i + 1] = max(equiv[i+1], above[i] + check(s1[3*i + 2], s2[3*i + 1], s2[3*i + 2]));
        equiv[i + 1] = max(equiv[i+1], below[i] + check(s2[3*i + 2], s1[3*i + 1], s1[3*i + 2]));

        above[i + 1] = above[i] + check(s1[3*i + 2], s1[3*i + 3], s1[3*i + 4]) + check(s2[3*i + 1], s2[3*i + 2], s2[3*i + 3]);
        below[i + 1] = below[i] + check(s2[3*i + 2], s2[3*i + 3], s2[3*i + 4]) + check(s1[3*i + 1], s1[3*i + 2], s1[3*i + 3]);
    }

    cout << equiv[n / 3] << endl;
    return;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}