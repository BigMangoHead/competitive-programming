#include <iostream>
#include <vector>
using namespace std;

void run() {
    long long  h, n;
    cin >> h >> n;
    vector<long long> a(n);
    vector<long long> c(n);
    long long maxAttack = 0;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        maxAttack = max(maxAttack, a[i]);
    }
    long long maxCool = 0;
    for (int i=0; i < n; i++) {
        cin >> c[i];
        maxCool = max(maxCool, c[i]);
    }

    long long low = 1;
    long long high = 1 + h*maxCool / (maxAttack);

    while (low < high) {
        long long mid = (low + high) / 2;

        long long d = 0;
        for (int i=0; i < n; i++) {
            long long t = 1 + (mid - 1) / c[i];
            d += t*a[i];
        }

        //clog << mid << " " << d << endl;

        if (d >= h) {
            high = mid;
        } else if (d < h) {
            low = mid+1;
        }
    }

    cout << low << endl;
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