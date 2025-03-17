#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int a, b, d, e;
    cin >> a >> b >> d >> e;
    int n1 = a + b;
    int n2 = d - b;
    int n3 = e - d;
    int count = 1;
    if (n1 == n2 || n1 == n3) count++;
    if (n2 == n3) count++;
    cout << count << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}