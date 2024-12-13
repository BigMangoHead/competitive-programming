#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    cout << string(n-1, '0') + '1' << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}