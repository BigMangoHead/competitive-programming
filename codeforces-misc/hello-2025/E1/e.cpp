#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

struct Node {
    vector<pair<int, int>> neigh; // Vertex, weight across edge
    
    void connect(int v, int weight) {
        neigh.push_back({v, weight});
    }
};

struct Edge {
    int x, y;
    int w;
};



void run() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Node> graph(n);
    vector<Edge> edges(m);

    for (int i=0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        Edge e;
        e.x = x-1;
        e.y = y-1;
        e.w = w;
        edges[i] = e;

        graph[x-1].connect(y-1, w);
        graph[y-1].connect(x-1, w);
    }

    auto comp = [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    };

    sort(edges.begin(), edges.end(), comp);

    vector<vector<int>> dist(m);

    for (int i=0; i < edges.size(); i++) {
        auto& e = edges[i];

        deque<pair<int, int>> vq; // Vertex, distance
        vq.push_back({e.x, 0});
        vq.push_back({e.y, 0});
        vector<int> res(n, -10);
        cout << "A ";
        while (vq.size() > 0) {
            pair<int, int> v = vq.front();
            if (res[v.first] != -10) {
                vq.pop_front();
                continue;
            }
            res[v.first] = v.second;
            for (auto& v2 : graph[v.first].neigh) {
                if (res[v2.first] == -10) {
                    cout << v2.first << " ";
                    if (v2.second > e.w) {
                        vq.push_back({v2.first, v.second+1});
                    } else {
                        vq.push_front({v2.first, v.second});
                    }
                }
            }

            vq.pop_front();
        }
        dist[i] = res;
        for (int j=0; j < res.size(); j++) {
            cout << res[j] << " ";
        }
        cout << endl;
    }

    for (; q > 0; q--) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;
        y--;
        cout << "Res ";
        for (int j=0; j < edges.size(); j++) {
            if (dist[j][x] + dist[j][y] < k) {
                //cout << j << "-" << dist[j][x] << "-" << dist[j][y] << "-";
                cout << edges[j].w << " ";
                break;
            }
        }
    }
    cout << "\n";


    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        // clog << "Case " << i+1;
        run();
    } 
}