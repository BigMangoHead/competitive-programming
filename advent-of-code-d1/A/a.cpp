#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void run() {
    vector<int> a(1000);
    vector<int> b(1000);
    for (int i=0; i < 1000; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int total = 0;
    for (int i=0; i < 1000; i++) {
        total += abs(a[i] - b[i]);
    }
    cout << total << endl;
}

int main(void) {
    run();
}