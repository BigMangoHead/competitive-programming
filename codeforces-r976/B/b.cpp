#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


void run() {
    long long n;
    cin >> n;

    long double root = sqrt(n);
    n += root;
    long double root2 = sqrt(n);
    if ((long) root2 > (long) root) {
        n++;
    }
    cout << n << endl;
}


int main(void) {
    int testcases;
    cin >> testcases;
    for (int i=0; i < testcases; i++) {
        run();
    }
}