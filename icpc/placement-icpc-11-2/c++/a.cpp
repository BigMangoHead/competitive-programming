#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    int len, a, b, told, r;
    cin >> len >> a >> b >> told >> r;
    double t = told;
    double pauseDist = a * t;
    double drinkDist = b * r;

    int n;
    cin >> n;
    vector<long long> sdist(n);
    vector<double> stime(n);
    for (int i=0; i < n; i++) {
        cin >> sdist[i];
    }
    stime.push_back(0);

    for (int i=n-1; i >= 0; i++) {
        bool done = false;
        int j = i+1;
        double best_time = INT_MAX;
        while (!done) {
            double dist;
            if (j >= n) {
                if (j > n) break;
                dist = (len - sdist[i]);
            } else {
                dist = sdist[j] - sdist[i];
            }
            if (pauseDist >= dist) {
                best_time = min(best_time, dist / t);
            } else if (pauseDist + drinkDist >= dist) {
                best_time = min(best_time, t + ((dist - (drinkDist + pauseDist)) / a) + stime[j]);
                done = true;
            } else {
                best_time = min(best_time, t + stime[j]);
            }

            j++;
        }
        stime[i] = best_time;
    }

    cout << sti
    

    return 0;
}