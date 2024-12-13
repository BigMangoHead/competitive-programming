#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check(vector<int> & nums) {

}

int main(void) {
  constexpr int N = 1000;
  int count = 0;
  for (int i = 0; i < N; i++) {
    string line;
    getline(cin, line);
    vector<int> nums;

    string x = "";
    for (auto &c : line) {
      if (c != ' ') {
        x += c;
      } else {
        nums.push_back(stoi(x));
        x = "";
      }
    }
    nums.push_back(stoi(x));

    bool works;
    for (int j = 0; j < nums.size(); j++) {
      bool inc;
      if (j > 1) inc = (nums[1] > nums[0]);
      else if (j == 1) inc = (nums[2] > nums[0]);
      else inc = nums[2] > nums[1];

      works = true;
      for (int i = 1; i < nums.size(); i++) {

        int n1 = nums[i];
        int n2 = nums[i-1];
        if (i == j) continue;
        else if (i == j+1) {
            if (i == 1) continue;
            else n2 = nums[i-2];
        }

        int dif = abs(n1 - n2);
        if (dif < 1 || dif > 3) {
          works = false;
          break;
        } else if (n1 > n2 && !inc) {
          works = false;
          break;
        } else if (n1 < n2 && inc) {
          works = false;
          break;
        }
      }
      if (works) break;
    }
    count += works ? 1 : 0;
  }
  cout << count << endl;
}