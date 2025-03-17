#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> count;
    for (int i=0; i < n ; i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    int l = 0;
    int best = 0;
    int start = 0;
    int bs, es;
    for (int i=0; i < n; i++) {
        if (count[a[i]] == 1) l++;
        else {
            if (best < l) {
                best = max(l, best);
                bs = start;
                es = i-1;
            }
            start = i+1;
            l = 0;
        }
    }
    if (best < l) {
        best = max(l, best);
        bs = start;
        es = n-1;
    }

    if (best == 0) {
        cout << '0' << endl;
    } else {
        cout << bs+1 << ' ' << es+1 << "\n";
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}