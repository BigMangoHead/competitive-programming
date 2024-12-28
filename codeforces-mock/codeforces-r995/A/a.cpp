#include <iostream>
#include <vector>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }

    int dif = a[n-1];
    for (int i=0; i < n-1 ; i++) {
        if (b[i+1] - a[i] < 0) {
            dif += a[i] - b[i+1];
        } 
    }
    cout << dif << endl;
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