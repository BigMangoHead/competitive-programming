#include <iostream>
#include <vector>
using namespace std;
#define ll long long

bool isPowTwo(int x) {
    while (x % 2 == 0) x /= 2;
    return (x == 1);
}

void run() {
    int n;
    cin >> n;

    if (isPowTwo(n) || isPowTwo(n+1)) {
        cout << "-1\n";
        return;
    }

    int pow = 0;
    while (n > 1) {
        n /= 2;
        pow++;
    }
    
    int x = 0;
    while (pow > 0) {
        x <<= 1;
        x++;
        pow--;
    }

    cout << x << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
