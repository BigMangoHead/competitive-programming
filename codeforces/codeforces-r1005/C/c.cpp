#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> ps(n);
    vector<ll> ss(n);
    ll sum = 0;
    for (int i=0; i< n; i++) {
        cin >> a[i];
        sum+= abs(a[i]);
        ps[i] = sum;
    }
    for (int i=0; i < n; i++) {
        ss[i] = sum - ps[i] + abs(a[i]);
    }

    int start = 0;
    int end = n-1;
    int nend = n-1; // end of negative values
    int pst = 0; // start of positive values
    ll score = 0;
    while (start <= end) {
        if (a[start] > 0) {
            score += a[start];
            start++;
        } else if (a[end] < 0) {
            score -= a[end];
            end--;
        } else {
            int pos;
            int neg;
            while (pst <= end) {
                if (a[pst] > 0) {
                    pos = pst;
                    break;
                }
                pst++;
            }
            while (nend >= start) {
                if (a[nend] < 0) {
                    neg = nend;
                    break;
                }
                nend--;
            }

            if (ps[neg] - ps[start] + abs(a[start]) > ss[pos] - ss[end] + abs(a[end])) {
                cout << "neg" << endl;
                end = neg - 1;
                score -= a[neg];
            } else {
                cout << "pos" << endl;
                start = pos + 1;
                score += a[pos];
            }
        }
        pst = max(start, pst);
        nend = min(nend, end);
    }
    cout << score << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}