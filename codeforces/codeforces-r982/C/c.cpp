#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int helper(vector<long long> & nums) {
    int best = 0;
    for (int i=1; i < nums.size(); i++) {
        if (nums[i] == 0) {
            //cout << "DEBUG " << i << " ";
            for (int j=0; j < nums.size(); j++) {
                nums[j] -= i;
            }
            best = max(best, helper(nums) + i);
            for (int j=0; j < nums.size(); j++) {
                nums[j] += i;
            }
        }
    }
    return best;
}

void run() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i=0; i < n; i++) {
        cin >> nums[i];
        nums[i] -= n - i;
    }

    cout << helper(nums) + nums.size() << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}