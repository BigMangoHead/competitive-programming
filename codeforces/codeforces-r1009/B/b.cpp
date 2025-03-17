#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        sum += x - 1;
    }
    cout << sum + 1 << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
