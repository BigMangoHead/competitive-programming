#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> rCount(m, 0);
    vector<int> cCount(n, 0);

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                cCount[i]++;
                rCount[j]++;
            }
        }
    }

    int r, c;
    r = distance(rCount.begin(), max_element(rCount.begin(), rCount.end()));
    c = distance(cCount.begin(), max_element(cCount.begin(), cCount.end()));
    cout << c+1 << " " << r+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}