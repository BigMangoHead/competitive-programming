#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<long long> a(n);
    set<long long> aset;
    vector<long long> s(n);
    long long sum = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    for (int i=0; i < n; i++) {
        sum += a[i];
        s[i] = sum;
    }

    int count = 0;
    for (int i=0; i < n; i++) {
        aset.insert(a[i]);
        long long goal = s[i];
        if (goal % 2 == 1) continue;
        goal /= 2;

        if (aset.find(goal) != aset.end()) {
            count++;
        }
    }

    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}