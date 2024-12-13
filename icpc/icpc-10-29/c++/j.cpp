#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool checkPrime(int x) {
    int sqx = sqrt(x);
    for (int i=2; i <= sqx; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<pair<int, int>> primes;
    for (int i=0; i < n; i++) {
        cin >> nums[i];
    }

    int x = 1;
    int bestnum = 1;
    int moves = 0;
    while (x+1 <= *max_element(nums.begin(), nums.end())) {
        x++;
        if (!checkPrime(x)) {
            continue;
        }

        vector<int> count(n, 0);
        int sum = 0;
        for (int i=0; i < nums.size(); i++) {
            while (nums[i] % x == 0) {
                nums[i] /= x;
                count[i]++;
                sum++;
            }
        }

        int res = sum / n;

        if (res == 0) continue;

        bestnum *= pow(x, res);
        for (int i=0; i < nums.size(); i++) {
            if (count[i] < res) moves += res - count[i];
        }
    }

    cout << bestnum << " " << moves << endl;

    return 0;
}