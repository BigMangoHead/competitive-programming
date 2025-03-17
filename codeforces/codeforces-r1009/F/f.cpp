#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<int> getPartition(int l, int r) {
    vector<int> p;
    while (l < r) {
        int lc = l;
        int dif = 1;
        while (lc % 2 == 0 && 2*dif <= r - l) {
            lc /= 2;
            dif *= 2;
        }
        p.push_back(dif);
        l += dif;
    }
    return p;
}

void run() {
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    vector<int> a = getPartition(l1, r1);
    vector<int> b = getPartition(l2, r2);
    //for (auto& v : b) clog << v << endl;
    long long sol = 0;
    for (auto& v : a) {
        for (auto& w : b) {
            sol += max(v, w) / min(v, w);
        }
    }
    cout << sol << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        //clog << "Case " << i+1 << endl;
        run();
    }
}
