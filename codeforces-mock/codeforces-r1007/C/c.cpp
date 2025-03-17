// After contest
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define ll long long

void run() {
    int n, s, e;
    cin >> n >> s >> e;

    vector<set<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    for (int i=0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        cout << x << ' ' << y << endl;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    queue<int> q;
    for (int i=1; i < n+1; i++) {
        if (deg[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int a = q.front();
        if (a == e) {
            q.pop();
            a = q.front();
        }
        q.pop();
        if (q.empty()) break;
        int b = q.front();
        if (b == e) {
            q.pop();
            if (q.empty()) break;
            b = q.front();
        }
        q.pop();

        cout << a << ' ' << b << ' ';
        for (auto& v : adj[a]) {
            adj[v].erase(adj[v].find(a));
            deg[v]--;
            if (deg[v] == 1) q.push(v);
        }
        for (auto& v : adj[b]) {
            adj[v].erase(adj[v].find(b));
            deg[v]--;
            if (deg[v] == 1) q.push(v);
        }

        deg[a]--;
        deg[b]--;
    }

    int pos;
    for (int i=1; i < n+1; i++) {
        if (deg[i] == 1 && i != e) {
            pos = i;
            break;
        }
    }

    while (pos != e) {
        cout << pos << ' ';
        int next = *(adj[pos].begin());
        adj[next].erase(adj[next].find(pos));
        pos = next;
    }
    cout << e << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
