#include <iostream>
#include <vector>
using namespace std;

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;
    int zCount = 0;
    int moveCount = 0;
    int prevOne = -1;
    for (int i=0; i < n; i++) {
        if (s[i] == '0') {
            zCount++;
        } else {
            if (zCount < m) {
                zCount = 0;
            } else {
                int cMoveCount = (zCount - m) / (m+k-1) + 1;
                moveCount += cMoveCount;

                int lastMovePos = prevOne+(m+k-1)*cMoveCount; // end position
                for (int j=lastMovePos; j > lastMovePos-k; j--) {
                    if (j >= n) continue;
                    s[j] = '1';
                }

                zCount = 0;
            }
            prevOne = i;
        }
    }
    if (zCount < m) {
        zCount = 0;
    } else {
        moveCount += (zCount-m) / (m+k-1);
        moveCount++;
        zCount = 0;
    }
    cout << moveCount << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        run();
    }
}