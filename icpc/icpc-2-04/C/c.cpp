#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define ll long long

struct Node {
    vector<pair<int, int>> neigh; // Node, weight
    int w;
};

int main(void) {
    int n;
    cin >> n;
    
    vector<Node> graph(n);
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        graph[i] = Node();
        graph[i].w = x;
    }

    int m;
    cin >> m;

    for (int i=0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        graph[x].neigh.push_back({y, w});
        graph[y].neigh.push_back({x, w});
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