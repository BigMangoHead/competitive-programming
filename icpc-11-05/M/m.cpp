#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    bool good = true;
    for (int i=0; i < 3; i++) {
        bool done = false;
        for (int j=0; j < n; j++) {
            int v;
            cin >> v;
            if (v == 7) {
                done = true;
                break;
            }
        }
        if (!done) {
            good = false;
            break;
        }
    }
    if (good) {
        cout << 777 << endl;
    } else cout << 0 << endl;


}