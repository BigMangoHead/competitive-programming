#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

struct classcomp {
    bool operator() (const pair<ll, ll>& lhs, const pair<ll, ll>& rhs) const
    {return lhs.first < rhs.first;}
};

void run() {
    int n, m;
    cin >> n >> m;

    set<pair<ll, ll>, classcomp> elem;
    for (int i=0; i < n; i++) {
        vector<int> a(m);
        ll sum = 0;
        ll s1 = 0;
        for (int j=0; j < m; j++) {
            cin >> a[i];
            s1 += a[i]*(m-j);
            sum += a[i];
        }
        elem.insert({s1 + sum*(n-1), sum});
    }

    ll score = 0;
    for (int i=0; i < n; i++) {
        score += (--elem.end())->first;
        elem.erase(--elem.end());

        set<pair<ll, ll>, classcomp> newelem;
        for (auto e : elem) {
            e.first -= e.second;
            newelem.insert(e);
        }
        elem = newelem;
    }
    cout << score << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}