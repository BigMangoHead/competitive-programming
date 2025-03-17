#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, mf, mg;
    cin >> n >> mf >> mg;
    vector<int> toid(n+1);         // Vertex to group ID
    vector<set<int>> fromid(n); // Group ID to vertices

    vector<pair<int, int>> fedge(mf);
    for (int i=0; i < mf; i++) {
        int x, y;
        cin >> x >> y;
        fedge[i] = {x, y};
    }

    for (int i=1; i <= n; i++) {
        toid[i] = i-1;
        fromid[i-1] = {i};
    }

    for (int i=0; i < mg; i++) {
        int x, y;
        cin >> x >> y;
        if (toid[x] == toid[y]) continue;
        set<int> &toRem = fromid[toid[x]];
        set<int> &toAdd = fromid[toid[y]];
        if (toAdd.size() < toRem.size()) {
            swap(x, y);
            swap(toAdd, toRem);
        }
        
        int newID = toid[y];


        for (auto& v : toRem) {
            toid[v] = newID;
            toAdd.insert(v);
        }
        toRem = {};
    }

    vector<int> ftoid(n + 1);     // Vertex to group ID
    vector<set<int>> ffromid(n); // Group ID to vertices

    for (int i=1; i <= n; i++) {
        ftoid[i] = i-1;
        ffromid[i-1] = {i};
    }

    int moves = 0;
    for (auto& e : fedge) {
        if (toid[e.first] != toid[e.second]) {
            moves++;
            continue;
        }

        int x, y;
        x = e.first; y = e.second;
        if (ftoid[x] == ftoid[y])
            continue;

        set<int>& toRem = ffromid[ftoid[x]];
        set<int>& toAdd = ffromid[ftoid[y]];
        if (toAdd.size() < toRem.size()) {
          swap(x, y);
          swap(toAdd, toRem);
        }

        int newID = ftoid[y];

        for (auto &v : toRem) {
            ftoid[v] = newID;
            toAdd.insert(v);
        }
        toRem = {};
    }

    int fcompcount = 0;
    for (auto& c : ffromid) {
        if (c.size() > 0) {
            fcompcount++;
        }
    }
    int gcompcount = 0;
    for (auto& c : fromid) {
        if (c.size() > 0) {
            gcompcount++;
        }
    }

    moves += fcompcount - gcompcount;
    cout << moves << "\n";

}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}