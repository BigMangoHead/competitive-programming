#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;
    string s = "";
    vector<int> lets(5, 0);
    for (int i=0; i < n; i++) {
        lets[i % 5]++;
    }

    string l = "aeiou";

    for (int j=0; j < 5; j++) {
        for (int k=0; k < lets[j]; k++) {
            s += l[j];
        }
    }

    cout << s << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        run();
    }
}