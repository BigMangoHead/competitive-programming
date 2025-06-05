#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define ll long long

void dfs(const vector<vector<int>>& adj, vector<int>& dist, int v) {
    int d = 0;
    dist[v] = 0;
    for (auto& w : adj[v]) {
        if (dist[w] == -1) dfs(adj, dist, w);
        if (dist[w] == 0) continue;
        d = max(dist[w], d);
    }
    dist[v] = d;
}

void dfs2(const vector<vector<int>>& adj, int v, int toadd) {

}

void run() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n, -1);
    dfs(adj, dist, 0);
    
    auto comp = [&](const int& a, const int& b) {
        return (dist[a] < dist[b]);
    };

    for (auto& v : adj) {
        sort(v.begin(), v.end(), comp);
    }

    vector<int> res(n, -1);
    dfs2(adj, 0, 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
