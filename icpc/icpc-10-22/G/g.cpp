#include <vector>
#include <iostream>
using namespace std;

void run(int n, int d, int m) {
    d = d*d;

    vector<vector<pair<int, int>>> moles(11);
    for (int i=0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        moles[t].push_back({x, y});
    }

    vector<pair<pair<int, int>, int>> hams;

    for (int i=1; i < 11; i++) {
        vector<pair<pair<int, int>, int>> temp;
        temp.clear();
        for (int j=0; j < moles[i].size(); j++) {
            temp.push_back({moles[i][j], 1});
            for (int k=0; k < hams.size(); k++) {
                if (pow(hams[k].first.first - moles[i][j].first, 2) + pow(hams[k].first.second - moles[i][j].second, 2) <= d) {
                    temp.push_back({moles[i][j], hams[k].second + 1});
                }
            }
        }

        for (int k=0; k < temp.size(); k++) {
            hams.push_back(temp[k]);
        }
    }

    int ma = 0;
    for (int i=0; i < hams.size(); i++) {
        ma = max(ma, hams[i].second);
    }
    cout << ma << endl;
}

int main(void) {
    while (true) {
        int n, d, m;
        cin >> n >> d >> m;
        if (n == 0) return 0;
        run(n, d, m);
    }
}