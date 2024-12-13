
// LESSON: Use big variable types!

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int a;
    cin >> a;

    for (int b = 0; b < a; b++) {
        int n;
        cin >> n;

        vector<int> people;
        int64_t sum =0;
        for (int i=0; i < n; i++) {
            int64_t x;
            cin >> x;
            sum += x;
            people.push_back(x);
        }

        if (n < 3) {
            cout << -1 << endl;
            continue;
        }

        sort(people.begin(), people.end());

        int64_t target = (people[n / 2]);
        //cout << "DEBUG: " << target << endl;

        int64_t result = 2*target * n + 1 - sum;

        if (result < 0) {
            result = 0;
        }
        cout << result << endl;


    }

    return 0;
}