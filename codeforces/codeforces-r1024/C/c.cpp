#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run(const vector<vector<int>>& a) {
    int n;
    cin >> n;

    int center = (521 - 1)/ 2;
    int start = center - ((n-1) / 2);
    int end = center + (n / 2);
    for (int i=start; i <= end; i++) {
        for (int j=start; j <= end; j++) {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }
}

const static pair<int, int> dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

vector<vector<int>> init() {
    const int n = 521;
    vector<vector<int>> a(n, vector<int>(n));
    int center = (n-1)/2;
    int posx = center + 1;
    int posy = center - 1;
    a[center][center] = 0;
    int num = 1;
    for (int i=0; i < n/2; i++) {
        for (int k=0; k < 4; k++) {
            for (int j=0; j < 2*(i+1); j++) {
                posx += dir[k].first;
                posy += dir[k].second;
                a[posx][posy] = num;
                num++;
            }
        }
        posx++;
        posy--;
    }
    return a;
}

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a = init();
    for (int i=0; i < n; i++) {

#ifdef LOCAL
        clog << "Case " << i+1 << endl;
#endif

        run(a);
    }
}
