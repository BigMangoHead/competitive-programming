#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/*
void run_old() {
    long long n, k;
    cin >> n >> k;
    int count = 0;
    if (k == 1) {
        cout << n << endl;
        return;
    }

    while (n > 0) {
        count++;
        if (n == 1) {
            break;
        }
        
        long long tmp = n;
        long long x = 0;
        //cout << "DEBUG ";
        while (tmp > 0) {
            tmp = n - pow(k, x) + 0.2;
            //cout << tmp << " ";
            x++;
        }
        //cout << endl;
        if (tmp == 0) {
            x--;
        } else {
            x -= 2;
        }
        n = n - pow(k, x) + 0.2;
    }

    cout << count << endl;
}
*/

long long getLargestPower(long long num, long long & base) {
    int powVal = 1;
    while (num / base > 0) {
        powVal *= base;
        num /= base;
    }
    return powVal;
}

void run() {
    long long n, k;
    cin >> n >> k;
    int count = 0;

    if (k == 1) {
        cout << n << endl;
        return;
    }

    int powVal = 1;
    while (n > 0) {
        powVal = getLargestPower(n ,k);
        //cout << powVal << " ";

        n -= powVal;
        count++;
    }
    
    cout << count << endl;
}


int main(void) {
    int testcases;
    cin >> testcases;
    for (int i=0; i < testcases; i++) {
        run();
    }
}