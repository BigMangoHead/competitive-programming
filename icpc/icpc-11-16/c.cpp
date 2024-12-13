
#include <iostream>
#include <vector>
using namespace std;

bool check(const int & upperBound, const int & n, const int & d, const int & c, vector<int> & stations) {
    int minCap = c;
    for (int i=0; i < n; i++) {
        if (stations[i] > upperBound) {
            minCap -= (stations[i] - upperBound);
            if (minCap < 0) return false;
        } else {
            minCap += upperBound - stations[i];
            minCap = min(minCap, c);
        }
    }
    return true;
}

int leastUpperBound(const int & n, int d, int c, vector<int> & stations) {
    int ptrA = 0;
    int ptrB = d;
    while (ptrA < ptrB) {
        bool works = check((ptrA + ptrB) / 2, n, d, c, stations);
        if (works) {
            ptrB = (ptrA + ptrB) / 2;
        } else {
            ptrA = (ptrA + ptrB) / 2 + 1;
        }
    }
    return ptrA;
}

int main(void) {
    int n, d, c;
    cin >> n >> d >> c;
    vector<int> stations(n);
    for (int i =0; i < n; i++) {
        cin >> stations[i];
    }

    int upper = leastUpperBound(n, d, c, stations);
    for (int i=0; i < n; i++) {
        stations[i] = d - stations[i];
    }
    int lower = d - leastUpperBound(n, d, c, stations);
    cout << upper - lower << endl;
}