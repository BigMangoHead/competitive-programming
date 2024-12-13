#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> start(c, vector<int>(r, 0));
    vector<vector<int>> end(c, vector<int>(r, 0));
    for (int i=0; i < r; i++) {
        for (int j=0; j < c; j++) {
            cin >> start[j][i];
            end[j][i] = start[j][i];
        }
    }

    for (int i=c-2; i >= 0; i--) {
        for (int j=0; j < r; j++) {
            end[i][j] = max(end[i][j], end[i+1][j]);
        }

        for (int j=1; j < r; j++) {
            end[i][j] = min(end[i][j], end[i][j-1]);
            end[i][j] = max(end[i][j], start[i][j]);
        }

        for (int j=r-2; j >= 0; j--) {
            end[i][j] = min(end[i][j], end[i][j + 1]);
            end[i][j] = max(end[i][j], start[i][j]);
        }  
    }

    for (int i=c-2; i > 1; i--) {
        for (int j=0; j < r; j++) {
            end[i][j] = max(end[i][j], end[i+1][j]);
        }

        for (int j=1; j < r; j++) {
            end[i][j] = min(end[i][j], end[i][j-1]);
            end[i][j] = max(end[i][j], start[i][j]);
        }

        for (int j=r-2; j >= 0; j--) {
            end[i][j] = min(end[i][j], end[i][j + 1]);
            end[i][j] = max(end[i][j], start[i][j]);
        }  
    }

    queue<pair<int, int>> updates;
    for (int i=0; i < c; i++) {
        for (int j=0; j < r; j++) {
            updates.push({i, j});
        }
    }
    while (updates.size() > 0) {
        pair<int, int> next = updates.front();
        updates.pop();

        if (end[next.first][next.second] == start[next.first][next.second]) continue;
        if (next.first < c-1) {
            if (end[next.first + 1][next.second] < end[next.first][next.second])
        }
        if (next.first > 0) {
            
        }

    }
}