#include <bits/stdc++.h>
using namespace std;

const pair<int, int> dir[8] = {{1, 0}, {1, 1}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
const string goal = "XMAS";

int main(void) {
    string ln;
    vector<string> data;
    while (cin >> ln) {
        data.push_back(ln);
    }

    int res = 0;
    for (int i=0; i < data.size(); i++) {
        for (int j=0; j < data[i].size(); j++) {
            if (data[i][j] == 'X') {
                for (auto & d : dir) {
                    int x = d.first;
                    int y = d.second;
                    if (i + 3*x < 0 || i + 3*x >= data.size() || i + 3*y < 0 || i + 3*y >= data[0].size()) {
                        continue;
                    }
                    for (int n=1; n <= 3; n++) {
                        int posX = i + n*x;
                        int posY = j + n*y;
                        if (data[posX][posY] != goal[n]) {
                            break;
                        }
                        if (n == 3) res++;
                    }
                }
            }
        }
    }
    cout << res;
}