#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    string s;
    cin >> s;
    int firstb = n;
    int firstc = n;
    for (int i=n-1; i >= 0; i--) {
        if (s[i] == 'b') firstb = i;
        else if (s[i] == 'c') firstc = i;
    }
    int posbc = 0;
    int poscb = 0;
    vector<pair<char, char>> ops(n);
    for (int i=0; i < n; i++) {
        char x, y;
        cin >> x >> y;
        ops[i] = {x, y};
        if (x == 'a') continue;
        if (y == 'a') {
            if (firstb < firstc) {
                if (x == 'b') s[firstb] = 'a';
                else {
                    if (posbc > 0) {
                        posbc--;
                        poscb++;
                        s[firstb] = 'a';
                    } else {
                        if (firstc != n) s[firstc] = 'a';
                    }
                }
            }
            else {
                if (x == 'c') s[firstc] = 'a';
                else {
                    if (poscb > 0) {
                        poscb--;
                        posbc++;
                        s[firstc] = 'a';
                    } else {
                        if (firstb != n) s[firstb] = 'a';
                    }
                }
            }

            while (firstb < n && s[firstb] != 'b') {
                firstb++;
            }
            while (firstc < n && s[firstc] != 'c') {
                firstc++;
            }
        }
        if (x == 'b' && y == 'c') posbc++;
        else if (x == 'c' && y == 'b') {
            poscb++;
        }

        if (firstb == n && firstc == n) break;
    }



    cout << s << '\n';
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
