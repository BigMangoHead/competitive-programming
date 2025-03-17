#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, k;
    cin >> n >> k;

    int val = n - ((k + 1) % 2);
    for (int i=0; i < n-2; i++) {
        cout << val << ' ';
    }
    cout << n << ' ' << n-1 << endl;
    
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
