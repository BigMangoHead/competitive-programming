#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int sign(vector<int> a) {
    
}

void run() {
    int n;
    cin >> n;
    vector<int> b1;
    vector<int> b2;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0) b1.push_back(x);
        else b2.push_back(x);
    }

    
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run();
    }
}
