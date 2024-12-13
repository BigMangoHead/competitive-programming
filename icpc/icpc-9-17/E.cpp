#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <algorithm>
#include <numbers>
using namespace std;

int main(void) {

    double r;
    int m;
    int c;
    while (true) {
        cin >> r >> m >> c;
        if (m == 0) {
            break;
        }
        double actual_area = M_PI * pow(r, 2);

        double calculated = (double) c / (double) m * 4*r*r;

        cout << actual_area << " " << calculated << endl;
    }

    return 0;
    
}