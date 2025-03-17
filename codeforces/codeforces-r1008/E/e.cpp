#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

void run() {
    int q = 0;
    for (int i=0; i < 15; i++) {
        q <<= 2;
        q += 1;
    }
    cout << q << endl;
    cout.flush();
    string x = "";
    int x1;
    cin >> x1;
    while (x1 > 0) {
        if (x1 % 2 == 1) x += '1';
        else x += '0';
        x1 /= 2;
    }
    q = 0;
    for (int i=0; i < 15; i++) {
        q <<= 2;
        q += 3;
    }
    cout << q << endl;
    cout.flush();
    int y1;
    cin >> y1;
    string y = "";
    while (y1 > 0) {
        if (y1 % 2 == 1) y += '1';
        else y += '0';
        y1 /= 2;
    }

    for (int i=0; i < 31; i++) {
        x += '0';
        y += '0';
    }

    int a = 0;
    int b = 0;
    int pow = 1;
    for (int i=0; i < 30; i+=2) {
        if (x[i] == '0' && x[i+1] == '0') ;
        else if (x[i] == '1') a += pow;
        else {
            a += pow;
            b += pow;
        }
        pow <<= 2;
    }
    pow = 2;
    for (int i=0; i < 30; i+= 2) {
        if (y[i+1] == '0' && y[i+2] == '0') ;
        else if (y[i+1] == '1') a += pow;
        else {
            a += pow;
            b += pow;
        }
        pow <<= 2;
    }

    cout << "!\n";
    cout.flush();
    int m;
    cin >> m;
    cout << ((a | m) + (b | m)) << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
