#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, r;
    cin >> n >> r;
    int even, odd = 0;
    int used = 0;
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        if (size % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        used += size / 2;
    }
    int rafter = r - used;
    if (odd <= rafter) {
        cout << used*2 + odd << endl;
        return;
    }

    cout << used*2 + rafter - (odd - rafter) << endl;
    return;
} 


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}