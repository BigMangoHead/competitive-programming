#include <ostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


void run(int n, int d, int m) {
    vector<pair<pair<int, int>, vector<pair<int, int>>>> movePos; // Each element is of the form (position, {set of positions this moves over})

    for (int i=-d; i <= d; i++) {
        for (int j=-d; j <= d; j++) {
            if (i*i + j*j <= d*d) {
                vector<pair<int, int>> possiblePos;
                possiblePos.clear();

                int gcd = 1;
                for (int k=2; k <= 5; k++) {
                    if (i % k == 0 && j % k == 0) gcd = k;
                }

                for (int n=0; n <= gcd; n++) {
                    possiblePos.push_back({(i / gcd) *n, (j / gcd)*n});
                }

                if (i == 0 && j == 0) possiblePos = {{0, 0}};

                movePos.push_back({{i, j}, possiblePos});
            }
        }
    }
    

    unordered_map<int, bool> moles(3*m); // Each key is an integer of the form 10000t + 100y + x

    for (int i=0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        moles[(x + d) + 100*(y + d) + 10000*t] = true;
    }

    vector<vector<int>> curr_best(n + 2*d, vector<int>(n + 2*d, 0));
    vector<vector<int>> prev_best(n + 2*d, vector<int>(n + 2*d, 0));
    
    for (int t=10; t >= 1; t--) {
        for (int x=0; x < n + 2*d; x++) {
            for (int y=0; y < n + 2*d; y++) {
                prev_best[x][y] = curr_best[x][y];
                curr_best[x][y] = 0;
            }
        }

        for (int x=0; x < n + 2*d; x++) {
            for (int y=0; y < n + 2*d; y++) {
                for (auto & move : movePos) {
                    int posx = x + move.first.first;
                    int posy = y + move.first.second;

                    if (posx < 0 || posy < 0 || posy >= n + 2*d || posx >= n + 2*d) continue;

                    int res = prev_best[posx][posy];
                    for (auto & posMoleRelPos : move.second) {
                        if (moles[x + posMoleRelPos.first + 100*(y + posMoleRelPos.second) + 10000*t]) {
                            res++;
                        }
                    }
                    //cout << "Res for (" << posx << ", " << posy << ") to (" << x << ", " << y << "): " << res << endl;
                    curr_best[x][y] = max(curr_best[x][y], res);
                }
            }
        }
    }

    int ma = 0;
    for (int x=0; x < n + 2*d; x++) {
        for (int y=0; y < n + 2*d; y++) {
            ma = max(ma, curr_best[x][y]);
        }
    }

    cout << ma << endl;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int n, d, m;
        cin >> n >> d >> m;
        if (n == 0) return 0;
        run(n, d, m);
    }
}
