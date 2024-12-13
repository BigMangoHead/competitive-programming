#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int count = 0;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) {
            count++;
        }
    }
    cout << count << endl;
}