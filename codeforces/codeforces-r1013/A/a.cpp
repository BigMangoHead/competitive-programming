#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    vector<int> count(10, 0);
    int n;
    cin >> n;
    bool flag = false;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
        if (!flag && count[0] >= 3 && count[1] >= 1 && count[2] >= 2 && count[5] >= 1 && count[3] >= 1) {
            cout << i+1 << endl;
            flag = true;
        }
    }
    //clog << count[0] << ' ' << count[1] << ' ' << count[2] << endl;
    if (!flag) cout << 0 << endl;
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
