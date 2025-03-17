#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ac = 1, bc = 1;
    for (int i=1; i < n; i++) {
        if (a[i] != a[i-1]) ac++;
    }
    for (int i = 1; i < n; i++) {
      if (b[i] != b[i - 1])
        bc++;
    }
    cout << (((max(ac, bc)>= 3) || (ac == 2) && (bc == 2)) ? "YES" : "NO") << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}