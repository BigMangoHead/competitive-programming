#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void run() {
    int n;
    cin >> n;
    string ns = to_string(n);

    int firstHalf = stoi(ns.substr(0, 3));

    int best = INT_MAX;
    int bestNum = -1;
    for (int i=-1; i <= 1; i++) {
        int nowFirstHalf = firstHalf + i;
        string nfhString = to_string(nowFirstHalf);
        reverse(nfhString.begin(), nfhString.end());

        int res = nowFirstHalf * (pow(10, nfhString.size())) + stoi(nfhString);
        if (abs(res - n) < best) {
            best = abs(res - n);
            bestNum = res;
        }
    }

    cout << bestNum << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    }
}