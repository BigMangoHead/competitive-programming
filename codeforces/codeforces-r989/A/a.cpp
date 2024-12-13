#include <iostream>
#include <vector>
using namespace std;

void run() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int m = a;
    while (true) {
        if (m % a == m % b) {
            cout << m << endl;
            return;
        }
        m++;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}