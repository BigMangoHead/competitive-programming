#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    cout << "mul 9" << endl;
    cout.flush();
    int a;
    cin >> a;
    cout << "digit" << endl;
    cout.flush();
    cin >> a;
    cout << "digit" << endl;
    cout.flush();
    cin >> a;
    cout << "add " + to_string(n-9) << endl;
    cout.flush();
    cin >> a;
    cout << "!" << endl;
    cout.flush();
    cin >> a;
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
