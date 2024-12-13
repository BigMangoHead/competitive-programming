#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    double dogx, dogy, gopx, gopy;
    cin >> gopx >> gopy >> dogx >> dogy;

    vector<pair<double, double>> holes;

    double x, y;
    while (cin >> x >> y) {
        if (x == 0) {
            break;
        }
        holes.push_back({x, y});
    }

    auto comp = [&] (const pair<double, double> & a, const pair<double, double> & b) {
        bool ans = pow(b.first - gopx, 2) + pow(b.second - gopy, 2) > pow(a.first - gopx, 2) + pow(a.second - gopy, 2);

        return ans;
    };

    sort(holes.begin(), holes.end(), comp);

    double betweendist = pow(dogx - gopx, 2) + pow(dogy - gopy, 2);
    for (const auto & hole : holes) {
        double gopdist = pow(hole.first - gopx, 2) + pow(hole.second - gopy, 2);
        double dogdist = pow(hole.first - dogx, 2) + pow(hole.second - dogy, 2);

        if (gopdist > betweendist) {
            break;
        }

        if (dogdist > 4*gopdist) {
            double convx = ((double) (int)(hole.first*1000))/1000;
            double convy = ((double) (int)(hole.second*1000))/1000;
            cout << "The gopher can escape through the hole at (" << convx << "," << convy << ").";
            return 0;
        }
    }

    cout << "The gopher cannot escape.";

    return 0;
}