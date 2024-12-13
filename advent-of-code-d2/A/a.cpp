#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    constexpr int N=1000;
    int count =0;
    for (int i=0; i < N; i++) {
        string line;
        getline(cin, line);
        vector<int> nums;

        string x = "";
        for (auto & c : line) {
            if (c != ' ') {
                x+= c;
            } else {
                nums.push_back(stoi(x));
                x = "";
            }
        }
        nums.push_back(stoi(x));
        
        bool inc = (nums[1] > nums[0]);
        bool works = true;
        for (int i=1; i < nums.size(); i++) {
            int dif = abs(nums[i] - nums[i-1]);
            if (dif < 1 || dif > 3) {
                works = false;
                break;
            } else if (nums[i] > nums[i-1] && !inc) {
                works = false;
                break;
            } else if (nums[i] < nums[i-1] && inc) {
                works = false;
                break;
            }
        }
        count += works ? 1 : 0;
    }
    cout << count << endl;
}