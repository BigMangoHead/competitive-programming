#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int x;
    cin >> x;
    ll res = (x / 15)*3;
    res++;
    if (x % 15 > 0) res++;
    if (x % 15 > 1) res++;
    cout << res << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}