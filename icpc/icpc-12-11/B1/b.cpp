#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, m, q;
    cin >> n >> m >> q;

    int posN, posA, posB;
    cin >> posA >> posB >> posN;

    if (posA > posB) {
        int tmp = posA;
        posA = posB;
        posB = tmp;
    }

    if (posN < posA) {
        cout << posA - 1 << endl;
    } else if (posN < posB) {
        cout << (posB - posA) / 2 << endl;
    } else {
        cout << n - posB << endl;
    }
}

int main(void) {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        run();
    }
}