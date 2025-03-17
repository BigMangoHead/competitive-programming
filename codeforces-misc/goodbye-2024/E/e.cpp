#include <algorithm>
#include <climits>
#include <cstdint>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define ll long long

struct Node {
    vector<Node*> n;
    int deg = 0;
    int d = INT_MAX;
    bool checked = false;
    int dBig = 0;
    int dZero = 0;
    int l = 0;
    int c = 0;
};

tuple<int, int, int> dTwoCount(Node* v, int l) {
    if (v->checked) return {v->dBig, v->dZero, v->c};
    v->checked = true;
    int res = 0;
    int res2 = 0;
    int c = 0;
    for (auto & n : v->n) {
        tuple<int, int, int> x = dTwoCount(n, l+1);
        res += get <0> (x);
        res2 += get<1>(x);
        c += get <2> (x);
    }
    if (v->d >= 2) res++;
    if (v->d == 0) res2++;
    c++;
    v->dBig = res;
    v->dZero = res2;
    v->c = c;
    v->l = l;
    return {res, res2, c};
}

void run() {
    int n;
    cin >> n;
    vector<Node*> g(n);
    for (int i=0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[x-1]->n.push_back(g[y-1]);
        g[y-1]->n.push_back(g[x-1]);
        g[x-1]->deg++;
        g[y-1]->deg++;
    }

    int done = 0;
    set<Node*> curDist;
    for (int i=0; i < n; i++) {
        if (g[i]->deg == 1) {
            curDist.insert(g[i]);
            g[i]->d = 0;
            done++;
        }
    }

    set<Node*> distOne;
    set<Node*> nextDist;
    int cd = 1;
    while (done < n) {
        for (auto & v : curDist) {
            for (auto & n : v->n) {
                if (n->d == INT_MAX) {
                    nextDist.insert(n);
                    n->d = cd;
                }
            }
        }
        if (cd == 1) distOne = nextDist;
        curDist = nextDist;
        cd++;
    }

    dTwoCount(g[0], 0);
    ll res = 0;
    ll zc = 0;
    for (auto & v : g) {
        if (v->d == 0) zc++;
    }
    res += zc*(((ll) n) - zc);

    for (auto & v : distOne) {
        for (auto & ne : v->n) {
            if (ne->l > v->l) { // Further down in tree
                res += ne->dBig * (n - ne->c - (g[0]->dZero - ne->dZero));
            } else {
                res += ne->dZero * (n - ne->c - (g[0]->dBig - ne->dBig));
            }
        }
    }

    cout << res << endl;
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}