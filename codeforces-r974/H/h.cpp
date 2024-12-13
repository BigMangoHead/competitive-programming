#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int a;
    cin >> a;

    for (int b = 0; b < a; b++) {
        int t, q;
        cin >> t >> q;

        vector<int> targets;
        for (int i=0; i < t; i++) {
            int x;
            cin >> x;
            targets.push_back(x);
        }

        
        vector<int> check(*max_element(targets.begin(), targets.end()) + 1, 0);
        for (int i=0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            if ((r - l) % 2 == 0) {
                cout << "NO" << endl;
                continue;
            }

            int nonzero = 0;
            for (int j=l-1; j < r; j++) {
                if (check[targets[j]] == 1) {
                    check[targets[j]] = 0;
                    nonzero--;
                } else if (check[targets[j]] == 0) {
                    check[targets[j]] = 1;
                    nonzero++;
                }
            }

            if (nonzero == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

            for (int j=l-1; j < r; j++) {
                check[targets[j]] = 0;
            }
            
        }
    }

    return 0;
}