#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define ll long long
#define pii pair<int, int>

// adj contains pairs of form {node index, weight}
int dijkstra(vector<vector<pii>>& adj, int start) {
    const int n = adj.size();
    vector<int> dist(n, LONG_LONG_MAX); 
    vector<bool> checked(n, false);

    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        pii cur = pq.top();
        int& v = cur.second; int& w = cur.first;
        if (checked[v]) continue;
        checked[v] = true;

        for (auto& n : adj[v]) {
            int newDist = dist[v] + n.second;
            if (newDist < dist[n.first]) {
                pq.push({newDist, n.first});
            }
        }
    }

    return dist[n-1];
}

int main(void) {
    int n;
    cin >> n;
    
    vector<vector<pair<int ,int>>> graph(n);
    vector<int> weight(n);
    for (int i=0; i < n; i++) {
        cin >> weight[i];
    }

    int m;
    cin >> m;

    for (int i=0; i < m; i++) {
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--;
        y--;
        graph[x].push_back({y, (w << 32) + });
    }

    vector<bool> checked(n, false);
    vector<ll> dist(n);
    vector<ll> obj(n);
    
    dist[0] = 0;
    obj[0] = graph[0].w;
    for (int i=1; i < n; i++) {
        dist[i] = LONG_LONG_MAX;
    }

    auto getMax = [&]() {
        int best = 0;
        ll best_dist = LONG_LONG_MAX;
        for (int i=0; i < n; i++) {
            if (checked[i]) continue;
            if (dist[i] < best_dist) {
                best = i;
                best_dist = dist[i];
            }
        }
        return best;
    };

    int i = 0;
    while (i < n) {
        int cur = getMax();
        //cout << cur << ' ' << dist[cur] << endl;

        for (auto& n : graph[cur].neigh) {
            int newDist = n.second + dist[cur];
            if (newDist <= dist[n.first]) {
                //cout << "UPDATE ";
                if (newDist == dist[n.first]) {
                    obj[n.first] = max(obj[n.first], obj[cur] + graph[n.first].w);
                } else {
                    obj[n.first] = obj[cur] + graph[n.first].w;
                }
                dist[n.first] = newDist;
            }
        }
        checked[cur] = true;
        i++;
    }

    if (dist[n-1] == LONG_LONG_MAX) {
        cout << "impossible";
        return 0;
    }
    cout << dist[n-1] << ' ' << obj[n-1];


}