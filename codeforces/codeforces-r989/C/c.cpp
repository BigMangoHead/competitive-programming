#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i=0; i < n; i++) {
        string s;
        cin >> s;
        for (int j=0; j < m; j++) {
            if (s[j] == 'U') grid[j][i] = 1;
            else if (s[j] == 'D') grid[j][i] = 2;
            else if (s[j] == 'L') grid[j][i] = 3;
            else if (s[j] == 'R') grid[j][i] = 4;
            else grid[j][i] = -1;
        }
    }

    deque<pair<int, int>> toCheck;
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (grid[i][j] != -1) toCheck.push_back({i, j});
        }
    }
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (grid[i][j] == -1) toCheck.push_back({i, j});
        }
    }

    vector<vector<int>> canEscape(m, vector<int>(n, -1));
    set<pair<int, int>> currPath;
    while (!toCheck.empty()) {
        pair<int, int> pos = toCheck.front();
        toCheck.pop_front();

        if (canEscape[pos.first][pos.second] != -1) continue;

        int posX = pos.first;
        int posY = pos.second;
        if (grid[pos.first][pos.second] == 1) posY--;
        else if (grid[pos.first][pos.second] == 2) posY++;
        else if (grid[pos.first][pos.second] == 3) posX--;
        else if (grid[pos.first][pos.second] == 4) posX++;
        else { // ? case
            bool good = false;
            for (int i=1; i <= 4; i++) {
                int posX = pos.first;
                int posY = pos.second;
                if (i == 1 || i == 3) posX += i-2;
                else posY += i-3;
                if (posX >= 0 && posX < m && posY >= 0 && posY < n) {
                    if (canEscape[posX][posY] != 1) {
                        good = true;
                        break;
                    }
                }
            }
            if (good) canEscape[pos.first][pos.second] = 0;
            else canEscape[pos.first][pos.second] = 1;
            continue;
        }

        if (posX < 0 || posX >= m || posY < 0 || posY >= n) {
            canEscape[pos.first][pos.second] = 1;
            for (auto & p : currPath) {
                canEscape[p.first][p.second] = 1;
            }
            currPath.clear();
        }

        else if (currPath.find({posX, posY}) != currPath.end()) {
            canEscape[pos.first][pos.second] = 0;
            for (auto & p : currPath) {
                canEscape[p.first][p.second] = 0;
            }
            currPath.clear();
        }

        else if (canEscape[posX][posY] == -1 && grid[posX][posY] != -1) {
            toCheck.push_front({posX, posY});
            currPath.insert(pos);
        }

        else {
            int res = canEscape[posX][posY];
            if (res == -1) res = 0;
            canEscape[pos.first][pos.second] = res;
            for (auto & p : currPath) {
                canEscape[p.first][p.second] = res;
            }
            currPath.clear();
        }
        //cout << "DEBUG " << pos.first << " " << pos.second << " " << canEscape[pos.first][pos.second] << endl;

    }

    int res = 0;
    for (auto & v : canEscape) {
        for (auto & e : v) {
            if (e == 0) res++;
        }
    }

    cout << res << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}