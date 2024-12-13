#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calcSol(const vector<int> & nums, const int & pos, int curr) {
    for (int i=pos; i < nums.size(); i++) {
        if (nums[i] > curr) curr++;
        else if (nums[i] < curr) curr--;
    }
    return curr;
}

void run() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i < n; i++) cin >> nums[i];

    int highest = 0;
    int curr = 0;
    int best = 0;
    for (int i=0; i < n; i++) {
        if (nums[i] > curr) {
            curr++;
            if (curr > highest) {
                highest = curr;
            } else if (nums[i] > highest) {
                best = max(best, calcSol(nums, i, highest));
            }
        } else if (nums[i] < curr) {
            curr--;
        }
    }
    if (best == 0) {
        bool isAlwaysIncreasing = true;
        curr = 0;
        for (int i=0; i < n; i++) {
            if (nums[i] > curr) curr++;
            else {
                isAlwaysIncreasing = false;
                break;
            }
        }
        if (isAlwaysIncreasing) {
            cout << curr - 1 << endl;
        } else {
            cout << curr << endl;
        }
    } else {
        cout << best << endl;
    }
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}