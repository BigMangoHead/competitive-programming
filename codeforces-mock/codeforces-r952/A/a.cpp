#include <iostream>
using namespace std;

void run() {
    string a, b;
    cin >> a >> b;
    char tmp = b[0];
    b[0] = a[0];
    a[0] = tmp;

    cout << a << ' ' << b << endl;
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