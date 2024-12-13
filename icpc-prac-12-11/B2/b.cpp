#include <bits/stdc++.h>
using namespace std;

void run() {
    int n, m, qCount;
    cin >> n >> m >> qCount;

    vector<int> t(m);
    vector<int> ql(qCount);
    for (int i=0; i < m; i++) {
        cin >> t[i];
    }
    for (int i=0; i < qCount; i++) {
        cin >> ql[i];
    }

    sort(t.begin(), t.end());

    for (auto q : ql) {
        int posA = 0;
        int posB = m-1;
        while (posA < posB) {
            int mid = (posA + posB) / 2;
            if (t[mid] > q) {
                posB = mid;
            } else if (t[mid] < q) {
                posA = mid+1;
            }
        }
        if (t[posA] < q) {
            posA++;
        }

        if (posA == 0) {
            cout << t[posA] - 1 << endl;
        } else if (posA == m) {
            cout << n - t[m-1] << endl;
        } else {
            cout << (t[posA] - t[posA-1])/2 << endl;
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        run();
    }
}