#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;
    string res;
    char things[5] = {'a','i','e','o','u'};
    int mod = n%5;
    int p = 0;
    for (int i=0; i<5; i++) {
        int num = n/5;
        if (i<mod) {
            num++;
        }
        for (int j=0; j<num; j++) {
            res += things[i];
            p++;
        }
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        run();
    }
}