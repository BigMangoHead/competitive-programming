#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i < n; i++) {
        cin >> nums[i];
    }

    int best = n-1;
    for (int i=0; i < n - 1; i++) {
        int count = i;
        for (int j=i+1; j < n; j++) {
            if (nums[j] > nums[i]) {
                count++;
            }
        }
        best = min(best, count);
    }

    cout << best << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}