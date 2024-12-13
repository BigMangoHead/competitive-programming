#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    int maxh = 0, maxw = 0;
    for (int i=0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        maxh = max(h, maxh);
        maxw = max(w, maxw);
    }
    cout <<  2*(maxh + maxw) << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}