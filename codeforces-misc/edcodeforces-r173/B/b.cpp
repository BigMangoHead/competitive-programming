#include <iostream>
using namespace std;
#define ll long long

void run() {
    ll n;
    cin >> n;
    int d;
    cin >> d;

    cout << 1 << " ";

    if (d % 3 == 0 || n >= 3) {
        cout << 3 << " ";
    }

    if (d == 5) {
        cout << 5 << " ";
    }

    if (d == 7 || n >= 3) {
        cout << 7 << " ";
    }

    if (d == 9 || n >= 6 || (n >= 3 && d % 3 == 0)) {
        cout << 9 << " ";
    }



    cout << endl;
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