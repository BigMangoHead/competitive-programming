#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m;
    cin >> n >> m;
    //vector<pair<int, int>> h(n);
    vector<vector<int>> all(n, vector<int>(m+1));
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        all[i][0] = i+1;
        all[i][1] = x;
        for (int j=0; j < m-1; j++) {
            int x;
            cin >> x;
            all[i][j+2] = x;
        }
        sort(all[i].begin()+1, all[i].end());
    }

    auto comp = [&](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    };

    sort(all.begin(), all.end(), comp);

    int cur = -1;
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            int& e = all[j][i+1];
            //cout << e << "\n";
            if (e <= cur) {
                cout << "-1" << "\n";
                return;
            }
            cur = e;
        }
    }

    for (auto &e : all) {
        cout << e[0] << " ";
    }
    cout << "\n";

}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}