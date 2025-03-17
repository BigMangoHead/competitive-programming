#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define ll long long

const static int modulo = 998244353;

class ModInt {
    public: 
    long long value;
    ModInt() {
        value = 1;
    }

    ModInt(ll x) {
        value = x % modulo;
        if (value < 0) value += modulo;
    }

    ModInt operator+(ModInt const& x) {
        return ModInt(this->value + x.value);
    }

    ModInt operator*(ModInt const& x) {
        return ModInt(this->value * x.value);
    }

    void operator+=(ModInt const& x) {
        this->value = (this->value + x.value) % modulo;
    }

    void operator*=(ModInt const& x) {
        this->value = (this->value * x.value) % modulo;
    }

    ModInt operator+(ll const& x) {
        return ModInt(this->value + x);
    }

    ModInt operator*(ll const& x) {
        return ModInt(this->value * x);
    }

    ModInt pow(long long e) {
        e--;
        ModInt res(this->value);
        ModInt cur(this->value);
        while (e > 0) {
            if (e % 2 == 1) {
                res *= cur;
                e--;
            } else {
                cur *= cur;
                e /= 2;
            }
        }
        return res;
    }
};

void run() {
    int n;
    cin >> n;

    vector<int> dist(n, -1);
    dist[0] = 0;
    vector<vector<int>> child(n); // children
    vector<int> par(n); // index of parent

    for (int i=1; i < n; i++) {
        int x;
        cin >> x;
        par[i] = x-1;
    }

    int maxdist = 0;

    for (int i=1; i < n; i++) {
        int curr = i;
        child[par[curr]].push_back(curr);
        stack<int> toup;
        while (dist[curr] == -1) {
            toup.push(curr);
            curr = par[curr];
        }
        int d = dist[curr];
        while (toup.size() > 0) {
            d++;
            maxdist = max(maxdist, d);
            int c = toup.top();
            dist[c] = d;
            toup.pop();
        }
    }

    vector<int> dcount(maxdist+1);
    for (int i=0; i < n; i++) {
        dcount[dist[i]]++;
    }

    vector<ModInt> ways(n);
    vector<int> cv;
    for (auto& v : child[0]) {
        cv.push_back(v);
    }
    int cd = 2;
    while (cv.size() > 0) {
        vector<int> nv;
        for (auto& v : cv) {
            //cout << 't' << ' ' << dcount[cd+1] << ' ' << cc << endl; 
            for (auto &c : child[v]) {
                nv.push_back(c); 
                ways[c] = ways[v] * (dcount[cd-1] - 1);
            }
        }
        cv = nv;
        cd++;
    }

    ModInt res(0);
    for (auto& v : ways) {
        //cout << v.value << ' ';
        res += v;
    }
    //cout << "\n";
    cout << res.value << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}