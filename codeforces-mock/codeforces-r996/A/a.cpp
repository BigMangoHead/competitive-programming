#include <iostream>
using namespace std;

void run() {
    int n;
    int a, b;
    cin >> n >> a >> b;
    cout << (((b-a +1000) % 2 == 0) ? "yes" : "no") << endl;
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