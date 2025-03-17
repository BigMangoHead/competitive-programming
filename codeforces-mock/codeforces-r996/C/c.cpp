#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int r, c;
    string p;
    cin >> r >> c >> p;
    vector<vector<long long>> a(r, vector<long long>(c));
    for (int i=0; i < r; i++) {
        vector<long long> row(c);
        for (int j=0; j < c; j++) {
            cin >> row[j];
        }
        a[i] = row;
    }

    int pos = 0;
    int i=0;
    int j=0; 
    while (pos <= p.size()) {
            bool which;
            if (pos == p.size()) which = !(p[pos-1] == 'D');
            else which = (p[pos] == 'D');
            if (which) {
                long long sum = 0;
                for (int k=0; k < c; k++) {
                    sum += a[i][k];
                }
                a[i][j] = -1*sum;
            } else {
                long long sum = 0;
                for (int k=0; k < r; k++) {
                    sum += a[k][j];
                }
                a[i][j] = -1*sum;
            }
        if (pos >= p.size()) {

        } else if (p[pos] == 'D') {
            i++;
        } else {
            j++;
        }
        
        pos++;
        
    }

    for (const auto& v : a) {
        for (const auto& e : v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    } 
}