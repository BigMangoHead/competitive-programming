#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m);
    set<int> q;
    for (int i=0; i < m; i++) {
        cin >> a[i];
    }
    for (int i=0; i < k; i++) {
        int x;
        cin >> x;
        q.insert(x);
    }



    if (k == n) {
        string res = "";
        for (int i=0; i < m; i++) {
            res += '1';
        }
        cout << res << endl;
        return;
    } else if (k < n-1) {
        string res = "";
        for (int i=0; i < m; i++) {
            res += '0';
        }
        cout << res << endl;
        return;
    }

    int missing = -1;
    for (int i=1; i <= n; i++) {
        if (q.find(i) == q.end()) {
            missing = i;
            break;
        }
    }

    string res = "";
    for (int i=0; i < m; i++) {
        if (a[i] == missing) {
            res += '1';
        } else {
            res += '0';
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
        run();
    } 
}