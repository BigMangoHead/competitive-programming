#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n, k;
    cin >> n >> k;

    vector<int> cards(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        cards[i] = x;
    }

    sort(cards.begin(), cards.end());

    vector<int> curr_count(k, 0);
    int prev_val = cards[0];
    int curr_val;
    int frontpos = 0;
    int backpos = 0;
    int amount = 0;
    int ma = 0;
    for (int i=0; i < n; i++) {
        curr_val = cards[i];
        if (curr_val == prev_val) {
            curr_count[frontpos] ++;
            amount++;
        } else if (curr_val == prev_val + 1) {
            frontpos++;
            frontpos %= k;
            amount++;
            prev_val = curr_val;
            if (frontpos == backpos) {
                amount -= curr_count[backpos];
                backpos++;
                backpos %= k;
            }
            curr_count[frontpos] = 1;
        } else {
            frontpos++;
            frontpos %= k;
            backpos = frontpos;
            curr_count[frontpos] = 1;
            prev_val = curr_val;
            amount = 1;
        }
        ma = max(ma, amount);
    }
    cout << ma << endl;
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}