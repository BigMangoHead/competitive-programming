#include <vector>
#include <iostream>
using namespace std;

void run(int test) {
    int n;
    cin >> n;

    vector<pair<int, int>> input;
    for (int i=0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        input.push_back({x, y});
    }

    int twice_d = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            pair<int, int> q1 = input.at(i);
            pair<int, int> q2 = input.at(j);
            int ntd = abs(q2.first-q1.first) - abs(q2.second-q1.second);
            twice_d = max(ntd, twice_d);
        }
    }

    cout << "Case #" << test << ": " <<  (double)(twice_d) / 2.0 << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run(i+1);
    }
}