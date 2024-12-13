#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> temp;
    for (int i=0; i < n; i++) {
        int t;
        cin >> t;
        temp.push_back(t);
    }

    sort(temp.begin(), temp.end());

    int mult = -1;
    int pos = temp.size() / 2;
    for (int i=0; i < temp.size(); i++) {
        cout << temp[pos] << " ";
        pos = pos + (i + 1) * mult;
        mult *= -1;
    }

    return 0;
}