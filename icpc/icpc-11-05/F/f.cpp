#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m, s, p, q;
    cin >> n >> m >> s >> p >> q;

    int pages = ((n - 1) / m) + 1;
    vector<int> preselected(p);
    vector<int> toselect(q);
    for (int i=0; i < p; i++) {
        cin >> preselected[i];
    }
    for (int i=0; i < q; i++) {
        cin >> toselect[i];
    }

    int cost = 0;
    int pindex = 0;
    int tindex = 0;
    int highestonpage = m;
    int lowestChangedPage = INT_MAX;
    int highestChangedPage = 0;
    for (int i=0; i < pages; i++) {
        n -= m;
        if (n < 0) {
            m = n + m; // m is always amount on current page
        }

        vector<int> currPre;
        vector<int> currTo;

        while (pindex < preselected.size()) {
            int x = preselected[pindex];
            if (x > highestonpage) {
                break;
            }
            currPre.push_back(x);
            pindex++;
        }

        while (tindex < toselect.size()) {
            int x = toselect[tindex];
            if (x > highestonpage) {
                break;
            }
            currTo.push_back(x);
            tindex++;
        }


        // Case 1 - select all at start
        int best = 1 + (m - currTo.size());

        // Case 2 - deselect all at start
        best = min(best, (int) (1 + currTo.size()));

        // Case 3 - deselect some, then select rest
        int toDeselect = currPre.size();
        for (int i=0; i < currPre.size(); i++) {
            if (find(currTo.begin(), currTo.end(), currPre[i]) != currTo.end()) {
                toDeselect -= 2;
            }
        }
        best = min(best, (int) currTo.size() + toDeselect);

        highestonpage += m;
        cost += best;

        if(best > 0) {
            lowestChangedPage = min(lowestChangedPage, i + 1);
            highestChangedPage = max(highestChangedPage, i + 1);
        }
    }

    if (lowestChangedPage > highestChangedPage) {

    } else if (s <= lowestChangedPage) {
        cost += highestChangedPage - s;
    } else if (s >= highestChangedPage) {
        cost += s - lowestChangedPage;
    } else {
        int better = min(s - lowestChangedPage, highestChangedPage - s);
        int worse = max(s - lowestChangedPage, highestChangedPage - s);

        cost += 2*better + worse;
    }

    cout << cost << endl;
}