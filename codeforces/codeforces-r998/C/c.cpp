#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> count;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    int pairs = 0;
    for (auto& e : a) {
        if (count[e] <= 0) continue;
        count[e]--;
        if (count.find(k-e) != count.end()) {
            if (count[k-e] > 0) {
                count[k-e]--;
                pairs++;
            }
        }
    }

    cout << pairs << "\n";    
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}