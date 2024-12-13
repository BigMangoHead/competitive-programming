#include <climits>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    
    vector<int> q(n), j(n);
    vector<int> k(n);
    unordered_map<int, int> qPos, kPos, jPos;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        q[x-1] = i+1;
    }
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        k[x-1] = i+1;
    }
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        j[x-1] = i+1;
    }
    for (int i=0; i < n; i++) {
        qPos[q[i]] = i;
        kPos[k[i]] = i;
        jPos[j[i]] = i;
    }

    vector<pair<int, short>> posNums(n+1, {0, 0}); // Short: 1 for Q, 2 for K, 3 for J, 0 for not known yet
    posNums[1] = {1, -1};

    int qIndex = 0;
    int kIndex = 0;
    int jIndex = 0;
    while (q[qIndex] != 1) {
        posNums[q[qIndex]] = {1, 1};
        qIndex++;
    }
    while (k[kIndex] != 1) {
        posNums[k[kIndex]] = {1, 2};
        kIndex++;
    }
    while (j[jIndex] != 1) {
        posNums[j[jIndex]] = {1, 3};
        jIndex++;
    }

    for (int i=2; i < n+1; i++) {
        if (posNums[i].second == 0) continue;

        int pos = qPos[i];
        if (pos > qIndex) {
            int num = q[qIndex];
            while (num != i) {
                if (i < num) {
                    posNums[num] = {i, 1};
                }

                qIndex++;
                num = q[qIndex];
            }
        }
        pos = kPos[i];
        if (pos > kIndex) {
            int num = k[kIndex];
            while (num != i) {
                if (i < num) {
                    posNums[num] = {i, 2};
                }

                kIndex++;
                num = k[kIndex];
            }
        }
        pos = jPos[i];
        if (pos > jIndex) {
            int num = j[jIndex];
            while (num != i) {
                if (i < num) {
                    posNums[num] = {i, 3};
                }

                jIndex++;
                num = j[jIndex];
            }
        }
    }

    if (posNums[n].second != 0) {
        vector<pair<int, short>> ops;
        ops.push_back({n, posNums[n].second});
        int index = 0;
        while (true) {
            int nextNum = posNums[ops[index].first].first;
            if (nextNum == 1) break;

            ops.push_back({nextNum, posNums[nextNum].second});

            index++;
        }
        cout << "YES" << endl;
        cout << ops.size() << endl;

        for (int i=ops.size()-1; i >=0; i--) {
            if (ops[i].second == 1) cout << "q ";
            else if (ops[i].second == 2) cout << "k ";
            else if (ops[i].second == 3) cout << "j ";

            cout << ops[i].first;
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
}