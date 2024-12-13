#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

void perm(vector<int> & curr, vector<int> & rem, vector<char> & ops, vector<int> & nums, vector<int> & res) {
    if (rem.size() >= 1) {
        for (int i=0; i < rem.size(); i++) {
            vector<int> newrem(rem.size() - 1, 0);
            int pos = 0;
            for (int j=0; j < rem.size(); j++) {
                if (j == i) {
                    continue;
                }
                newrem[pos] = rem[j];
                pos++;
            }

            curr.push_back(rem[i]);
            perm(curr, newrem, ops, nums, res);
            curr.erase(curr.end(), curr.end());
        }
    }

    vector<int> vals = curr;

    for (int i=0; i < rem.size(); i++) {
        vals[curr[i] - 1]
    }
}

int main(void) {
    return 0;
    string input;
    while (getline(cin, input)) {
        if (input == "0") return 0;
        vector<int> nums;
        vector<char> ops;
        vector<int> rem;

        int val = 0;
        for (auto & s : input) {
            if (s == '*' || s == '+' || s == '-') {
                ops.push_back(s);
                rem.push_back(val);
                val++;
            } else if (s == ' ') {
                continue;
            } else {
                nums.push_back((int) s - 48);
            }
        }

        vector<int> curr, res;
        perm(curr, rem, ops, nums, res);
        sort(res.begin(), res.end());
        for (auto & x : res) {
            cout << x << endl;
        }
        cout << endl;
    }
    return 0;
}