#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    map<int, vector<int>> modulo;
    for (int i=0; i < n; i++) {
        cin >> nums[i];
        modulo[nums[i] % k].push_back(nums[i]);
    }

    long long ops = 0;
    bool hasOdd = false;
    for (auto & v : modulo) {
        vector<int> & cur = v.second;
        if (cur.size() == 0) {
            continue;
        } else if (cur.size() % 2 == 1 && hasOdd) {
            cout << -1 << endl;
            return;
        } else if (cur.size() % 2 == 1) {
            hasOdd = true;
            vector<int> & e = cur;
            sort(e.begin(), e.end());
            vector<int> fordif; // partial sums of differences moving forward
            vector<int> backdif; // partial sums of differences moving backwards

            fordif.push_back(0);
            backdif.push_back(0);
            int dif = 0;
            for (int i=0; i < e.size()-1; i+=2) {
                dif += e[i+1] - e[i];
                fordif.push_back(dif);
            }
            dif = 0;
            for (int j=e.size()-2; j >= 0; j -= 2) {
                dif += e[j+1] - e[j];
                backdif.push_back(dif);
            }

            long long mi = LONG_LONG_MAX;
            for (int i=0; i < fordif.size(); i++) {
                long long cost = fordif[i] + backdif[backdif.size() -1 - i];
                mi = min(mi, cost);
            }
            ops += mi / k;
        } else {
            sort(cur.begin(), cur.end());
            for (auto itr = cur.begin(); itr != cur.end(); itr++) {
                int a = *itr;
                itr++;
                int b = *itr;
                ops += (b - a) / k;
            } 
        }
    }

    cout << ops << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}