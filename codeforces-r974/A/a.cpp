#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        int r=0;
        int people;
        cin >> people;
        int thres;
        cin >> thres;
        int total = 0;

        for (int j=0; j < people; j++) {
            int gold;
            cin >> gold;
            
            if (gold >= thres) {
                r += gold;
            } else if (gold == 0 && r > 0) {
                total ++;
                r--;
            }
        }

        cout << total << endl;

    }

    return 0;
}