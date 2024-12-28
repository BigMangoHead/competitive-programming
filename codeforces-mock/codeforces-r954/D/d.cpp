#include <bits/stdc++.h>
#include <climits>
using namespace std;

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mi = INT_MAX;
    for (int i=0; i < n-1; i++) {
        int sum = 0;
        bool allones = true;
        for (int j=0; j < n; j++) {
            //cout << i << " " << j << endl;
            int k = s[j] - '0';
            if (j==i) {
                k *= 10;
                k += s[j+1] - '0';
            }

            if (k == 0) {
                cout << 0 << endl;
                //cout << 0 << endl;
                return;
            } else if (k != 1) {
                allones = false;
                sum += k;
            }

            if (j==i) {
                j++;
            }
        }
        if (allones) sum++;
        mi = min(mi, sum);
    }

    cout << mi << endl;
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