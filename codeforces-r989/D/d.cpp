#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i=0; i < n; i++) {
        cin >> stones[i];
    }
    vector<pair<int, int>> moves;

    int rZero = -1;
    int tmp = -1;
    int rOne = -1;
    for (int i=n-1; i >= 0; i--) {
        if (stones[i] == 0 && tmp == -1) {
            tmp = i;
        } else if (stones[i] == 0 && rZero == -1) {
            rZero = i;
        } else if (stones[i] == 1) {
            if (tmp == -1) {
                rZero = n-1;
                rOne = i;
            } else {
                stones[tmp] = 1;
                stones[i] = 0;
                moves.push_back({tmp, i});
                rZero = max(rZero, i);
                rOne = tmp;
            }
            break;
        }
    }

    int pos = 0;
    while (pos < n) {
        while (rZero >= 0 && stones[rZero] != 0) {
            rZero--;
        }
        while (rOne >= 0 && stones[rOne] != 1) {
            rOne--;
        }

        if (stones[pos] == 2) {
            if (rOne > pos) {
                moves.push_back({rOne, pos});
                stones[pos] = 1;
                stones[rOne] = 2;
            }
        } 
        if (stones[pos] == 1) {
            if (rZero > pos) {
                moves.push_back({rZero, pos});
                stones[pos] = 0;
                stones[rZero] = 1;
            }
        }

        pos++;
    }

    cout << moves.size() << endl;
    for (int i=0; i < moves.size(); i++) {
        cout << moves[i].first+1 << " " << moves[i].second+1 << endl;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}