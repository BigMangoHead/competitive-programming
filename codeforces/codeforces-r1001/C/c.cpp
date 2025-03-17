#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    long long best = INT_MIN;
    for (int k=0; k < n; k++) {
        long long sum = 0;
        for (auto& e : a) {
            sum += e;
        }
        best = max(best, sum);
        if (k != 0) best = max(best, -1*sum);

        for (int i=0; i < a.size()-1; i++) {
            a[i] = a[i+1] - a[i];
        }
        a.pop_back();
    }
    cout << best << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1;
        run();
    }
}