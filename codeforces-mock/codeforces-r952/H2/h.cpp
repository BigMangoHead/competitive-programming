#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Node {
    int id = -1;

    Node() {

    }
};

const static vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const static vector<pair<int, int>> dir2 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0}};

int fill(const int & id, vector<vector<Node>> & grid, const int & i, const int & j) {
    int size = 1;
    grid[i][j].id = id;
    for (auto & d : dir) {
        int posA = i + d.first;
        int posB = j + d.second;
        if (posA >= 0 && posA < grid.size() && posB >= 0 && posB < grid[0].size() && grid[posA][posB].id == 0) {
            size += fill(id, grid, posA, posB);
        }
    }
    return size;
}

void run() {
    int id = 10;
    int n, m;
    cin >> n >> m;
    vector<vector<Node>> grid(n, vector<Node>(m));
    map<int, int> sizeMap; // id to size

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            grid[i][j] = Node();
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j].id = 0;
            }
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (grid[i][j].id == 0) {
                int size = fill(id, grid, i, j);
                sizeMap[id] = size;
                id++;
            }
        }
    }

    vector<int> br(n);
    for (int i=0; i < n; i++) {
        int size = 0;
        set<int> ids;
        for (int j=0; j < m; j++) {
            if (grid[i][j].id == -1) {
                size++;
            }
            for (int x=-1; x < 2; x++) {
                if (i + x < 0 || i + x >= n) {
                    continue;
                }
                if (grid[i+x][j].id == -1) continue;
                auto f = ids.find(grid[i+x][j].id);
                if (f == ids.end()) {
                    ids.insert(grid[i+x][j].id);
                    size += sizeMap[grid[i+x][j].id];
                }
            }         
        }
        br[i] = size;   
    }

    vector<int> bc(m);
    for (int j=0; j < m; j++) {
        int size = 0;
        set<int> ids;
        for (int i=0; i < n; i++) {
            if (grid[i][j].id == -1) {
                size++;
            }
            for (int x=-1; x < 2; x++) {
                if (j + x < 0 || j + x >= m) {
                    continue;
                }
                if (grid[i][j+x].id == -1) continue;
                auto f = ids.find(grid[i][j+x].id);
                if (f == ids.end()) {
                    ids.insert(grid[i][j+x].id);
                    size += sizeMap[grid[i][j+x].id];
                }
            }         
        }
        bc[j] = size;
    }

    vector<vector<int>> o(n, vector<int>(m)); 

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            int count = 0;
            for (auto & d : dir2) {
                int posA = i + d.first;
                int posB = j + d.second;
                if (posA >= 0 && posA < n && posB >= 0 && posB < m && grid[posA][posB].id != -1) {
                    count++;
                }
            }
            o[i][j] = count;
        }
    }

    int ma = 0;
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            int cur = br[i] + bc[j] - o[i][j];
            ma = max(cur, ma);
        }
    }

    cout << ma << endl;

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "CASE " << i+1 << endl;
        run();
    } 
}