#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long

void run() {
    int s, k;
    cin >> s >> k;
    set<int> pos;
    pos.insert(0);
    for (int c = k; c > 0; c -= 2) {
        //for (auto& v : pos) clog << v << ' ';
        //clog << endl;
        set<int> newpos;
        for (auto& v : pos) {
            for (int x = s + (v % c) - (s % c); x > 0 && x >= s - c*c && x > v; x -= c) {
                if (x > s) continue;
                newpos.insert(x);
            }
        }
        if (newpos.find(s) != newpos.end()) {
            cout << c << "\n";
            return;
        }
        swap(pos, newpos);
        newpos.clear();
        //for (auto& v : pos) clog << v << ' ';
        //clog << endl;
        for (auto& v : pos) {
            for (int x = v % (c-1); (x < s && x <= (c-1)*(c-1) && x < v); x += c-1) {
                newpos.insert(x);
            }
        }
        swap(pos, newpos);
        newpos.clear();
    }
    cout << 1 << "\n";
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
