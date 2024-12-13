#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> perm(n);
    string dir;
    vector<int> breaks(n, 0);
    for (int i=0; i < n; i++) {
        cin >> perm[i];
    }
    cin >> dir;
    int breakcount = 0;
    for (int i=0; i < n-1; i++) {
        if (dir[i] == 'L' && dir[i+1] == 'R') {
            breaks[i] = 1;
            breakcount++;
        }
    }

    vector<int> queries(n);
    for (int i=0; i < q; i++) cin >> queries[i];

    vector<set<int>> blocks(breakcount + 1);
    vector<bool> blockworks(breakcount + 1, true);

    int currb = 0;
    for (int i=0; i < n; i++) {
        blocks[currb].insert(perm[i]);
        if (breaks[i] == 1) {
            currb++;
        }
    }

    currb = 0;
    bool works = true;
    int currsize = blocks[currb].size();
    for (int i=0; i < n; i++) {
        if (*blocks[currb].lower_bound(i) == i && ) {
            continue;
        } else {
            currb++;
            if (currb > breakcount) break;
            if (*blocks[currb].lower_bound(i) != i) {
                blockworks[currb - 1] = false;
                works = false;
            }
            currsize += blocks[currb].size();
        }
    }



}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}