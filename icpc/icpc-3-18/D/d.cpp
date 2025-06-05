#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    vector<int> a(6), b(6), c(6);
    for (int i=0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i=0; i < 6; i++) {
        cin >> b[i];
    }
    for (int i=0; i < 6; i++) {
        cin >> c[i];
    }

    vector<int> wins; // a vs. b, a vs. c, c vs. b

    for (int i=0; i < 3; i++) {
        int win[2] = {};
        for (int j=0; j < 6; j++) {
            for (int k=0; k < 6; k++) {
                if (a[j] > b[k]) win[0]++;
                else if (a[j] < b[k]) win[1]++;
            }
        }
        if (win[0] == 0 && win[1] == 0) wins.push_back(-1);
        else if (win[0] < win[1]) wins.push_back(1);
        else if (win[0] > win[1]) wins.push_back(0);
        else if (win[0] == win[1]) wins.push_back(2);
        if (i == 0) swap(b, c);
        else if (i == 1) {
            swap(b, c);
            swap(a, c);
        }
        else swap(a, c);
    }

    if ((wins[0] == 0 || wins[0] == 2) && (wins[1] == 0 || wins[0] == 2)) {
        cout << 1 << endl;
        return;
    } else if (wins[0] >= 1 && wins[2] >= 1) {
        cout << 2 << endl;
        return;
    } else if (wins[1] >= 1 && (wins[2] == 0 || wins[2] == 2)) {
        cout << 3 << endl;
        return;
    } else {
        cout << "No dice\n";
    }
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
