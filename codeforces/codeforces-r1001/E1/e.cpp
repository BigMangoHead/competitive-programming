#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define ll long long

struct Node {
    int index;
    vector<int> neigh;
    int parent = -101;
    int weight;
    bool marked = false;
};

void root(vector<Node>& graph, vector<bool>& checked, int index, int prev) {
    if (checked[index]) return;

    graph[index].parent = prev;
    checked[index] = true;
    for (auto& n : graph[index].neigh) {
        root(graph, checked, n, index);
    }
}

void run() {
    int n;
    cin >> n;

    vector<Node> graph(n);
    multiset<int> weight;
    for (int i=0; i < n; i++) {
        graph[i] = Node();
        int x;
        cin >> x;
        weight.insert(x);
        graph[i].weight = x;
        graph[i].index = i;
    }

    for (int i=0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x - 1].neigh.push_back(y - 1);
        graph[y - 1].neigh.push_back(x - 1);
    }

    vector<bool> checked(n, false);
    root(graph, checked, 0, -1);
    // for (auto& v : graph) {
    //     clog << v.parent << " ";
    // }
    // clog << endl;

    queue<int> bfs;
    int goal = *weight.rbegin();
    bfs.push(0);
    int v = -1;
    while (bfs.size() > 0) {
        int cur = bfs.front();
        bfs.pop();

        if (graph[cur].weight == goal) {
            v = cur;
            break;
        }

        for (auto& n : graph[cur].neigh) {
            if (n == graph[cur].parent) continue;
            bfs.push(n);
        }
    }

    while (weight.size() > 0 && *weight.rend() == goal) {
        weight.erase(--weight.end());
    }

    while (v != -1) {
        if (graph[v].weight != goal) weight.erase(weight.find(graph[v].weight));
        graph[v].marked = true;
        v = graph[v].parent;
    }
    for (auto& w : weight) {
        clog << w << " ";
    }
    clog << "\n";

    int resultw = -1;
    for (auto it = weight.rbegin(); it != weight.rend(); it++) {
        if (*it != goal) {
            resultw = *it;
        }
    }

    bfs.push(0);
    v = -1;
    while (bfs.size() > 0) {
        int cur = bfs.front();
        bfs.pop();

        if (graph[cur].weight == resultw && !graph[cur].marked) {
            v = cur;
            break;
        }

        for (auto& n : graph[cur].neigh) {
            if (n == graph[cur].parent) continue;
            bfs.push(n);
        }
    }
    cout << v+1 << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        clog << "Case " << i+1 << endl;
        run();
    }
}