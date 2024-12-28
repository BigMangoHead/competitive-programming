#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node {
    int id = -1;
    int size = 0;

    Node() {

    }
};

const static vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

void setSize(int & id, int & size, vector<vector<Node>> & grid, const int & i, const int & j) {
    if (grid[i][j].size != 0) return;
    grid[i][j].size = size;
    for (auto & d : dir) {
        int posA = i + d.first;
        int posB = j + d.second;
        if (posA >= 0 && posA < grid.size() && posB >= 0 && posB < grid[0].size() && grid[posA][posB].id == id) {
            setSize(id, size, grid, posA, posB);
        }
    }
}

void run() {
    int id = 10;
    int n, m;
    cin >> n >> m;
    vector<vector<Node>> grid(n, vector<Node>(m));

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
                setSize(id, size, grid, i, j);
                id++;
            }
        }
    }

    int best = 0;

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
                    size += grid[i+x][j].size;
                }
            }         
        }
        best = max(best, size);   
    }

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
                    size += grid[i][j+x].size;
                }
            }         
        }
        best = max(best, size);
    }

    cout << best << endl;

    
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