#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;

    string s, c;
    vector<int> v(m);
    cin >> s;
    for (int i=0; i < m; i++) {
        cin >> v[i];
        v[i]--;
    }
    cin >> c;
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());

    int cIndex = 0;
    for (int i=0; i < m; i++) {
        if (i > 0 && v[i] == v[i-1]) continue;
        int sIndex = v[i];

        s[sIndex] = c[cIndex];
        cIndex++;
    }

    cout << s << endl;
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