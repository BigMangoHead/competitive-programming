#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    for (int i=0; i < m; i++) {
        cin >> b[i];
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}