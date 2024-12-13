#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 1000;

void run() {
    unordered_map<int, long long> numCount; // number -> count
    vector<long long> nums(N);
    for (int i=0; i < N; i++) {
        cin >> nums[i];
        int x;
        cin >> x;
        numCount[x]++;
    }

    long long score = 0;
    for (int i=0; i < N; i++) {
        score += numCount[nums[i]]*nums[i];
    }
    cout << score << endl;
}

int main(void) {
    run();
}