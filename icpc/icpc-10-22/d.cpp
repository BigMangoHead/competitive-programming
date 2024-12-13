#include <vector>
#include <iostream>
using namespace std;

void floodFill(const int & target, vector<vector<int>> & depths, vector<vector<bool>> & flood, int x, int y) {
    if (flood[x][y]) return;
    flood[x][y] = true;
    
    if (x > 0 && depths[x-1][y] <= target) floodFill(target, depths, flood, x - 1, y);
    if (x < depths.size() - 1 && depths[x+1][y] <= target) floodFill(target, depths, flood, x + 1, y);
    if (y > 0 && depths[x][y-1] <= target) floodFill(target, depths, flood, x, y - 1);
    if (y < depths[0].size() - 1 && depths[x][y+1] <= target) floodFill(target, depths, flood, x, y+1);

}

int main(void) {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> depth(c, vector<int>(r));

    for (int i=0; i < r; i++) {
        for (int j=0; j < c; j++) {
            cin >> depth[j][i];
        }
    }

    int top = 1000000;
    int bottom = 0;

    while (bottom < top) {
        int target = (top + bottom) / 2;
        vector<vector<bool>> flood = vector<vector<bool>>(c, vector<bool>(r, false));

        for (int j=0; j < r; j++) {
            if (depth[c-1][j] <= target) floodFill(target, depth, flood, c-1, j);
        }

        bool check = false;
        for (int j=0; j < r; j++) {
            if (flood[0][j]) {
                check = true;
            }
        }

        if (check) top = target;
        else bottom = target+1;
    }

    cout << bottom << endl;


    return 0;
}