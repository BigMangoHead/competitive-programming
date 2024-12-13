#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isLetter(char & l) {
    return (l == 'n' || l == 'a' || l == 'r' || l == 'e' || l == 'k');
}

const string let = "narek";

void run() {
    int n, m;
    cin >> n >> m;
    vector<int> best(5, -2000000);
    best[0] = 0;
    for (int i=0; i < n; i++) {
        vector<int> oldbest = best;
        string s;
        cin >> s;
        int gptCount = 0;
        for (int k=0; k < m; k++) {
            if (isLetter(s[k])) {
                gptCount++;
            }
        }
        for (int j=0; j < 5; j++) {
            if (oldbest[j] == -2000000) continue;

            int currLetter = j;
            int nScore = 0;
            for (int k=0; k < m; k++) {
                if (s[k] == let[currLetter]) {
                    currLetter++;
                    if (currLetter == 5) {
                        currLetter = 0;
                        nScore += 5;
                    }
                }
            }

            int newScore = oldbest[j] + 2*nScore - gptCount;
            //clog << i << " " << j << " " << newScore << " " << best[currLetter] << endl;

            if (best[currLetter] < newScore) {
                best[currLetter] = newScore;
            }
        }
    }

    cout << *max_element(best.begin(), best.end()) << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    for (int i=0; i < n; i++) {
        run();
    }
}