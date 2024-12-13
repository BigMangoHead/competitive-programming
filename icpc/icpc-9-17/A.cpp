#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n;
    vector<vector<int>> points;
    cin >> n;

    int x;
    int y;
    for (int i=0; i < n; i++) {
        cin >> x;
        cin >> y;
        points.push_back(vector<int> {x, y});
    }

    for (int i=0; i < n; i++) {
        vector<int> center = points[i];
        // Check that next points around are on opposite sides of lines
        vector<int> left = points[(n + i - 1) % n];
        vector<int> right = points[(i + 1) % n];
    }


    return 0;
}