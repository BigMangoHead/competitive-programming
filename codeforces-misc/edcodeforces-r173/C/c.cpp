#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

void insertInterval(set<int> & v, int x, int y) {
    for (int a = x; a < y+1; a++) {
        v.insert(a);
    }
}

void part(vector<int> & a, int s, int e, set<int> & res) {
    int cMax = 0;
    int cMin = 0;
    int ma = 0;
    int mi = 0;

    for (int i=s; i < e+1; i++) {
        cMax += a[i];
        cMin += a[i];
        if (cMax < 0) cMax = 0;
        if (cMin > 0) cMin = 0;
        ma = max(cMax, ma);
        mi = min(cMin, mi);
    }

    insertInterval(res, mi, ma);
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int si = -1;
    for (int i=0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1) {
            si = i;
        }
    }

    set<int> res;
    res.insert(0);

    if (si == -1) {
        part(a, 0, n-1, res);
    } else {
        if (si > 0) part(a, 0, si - 1, res);
        if (si < n-1) part(a, si+1, n-1, res);

        int sum = a[si];
        int mi = sum;
        int ma = sum;
        for (int i=si+1; i < n; i++) {
            sum += a[i];
            mi = min(mi, sum);
            ma = max(ma, sum);
        }

        sum = a[si];
        int mi2 = sum;
        int ma2 = sum;
        for (int i=si-1; i >= 0; i--) {
            sum += a[i];
            mi2 = min(mi2, sum);
            ma2 = max(ma2, sum);
        }

        insertInterval(res, mi + mi2 - a[si], ma + ma2 - a[si]);
    }

    cout << res.size() << endl;
    for (auto & e : res) {
        cout << e << " ";
    }
    cout << endl;




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}