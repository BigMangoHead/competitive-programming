#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

const int k = 2;

void run(const int n) {
    long long res = 0;
    const int end = pow(10, n);
    for (int x = pow(10, n-1); x < end; x++) {
        int xc = x;
        int cd[10] = {};
        int i = 0;
        while (xc > 0) {
            i++;
            cd[xc % 10]++;
            xc /= 10;
        }
        cd[0] = n - i;
        //for (auto& v : cd) cout << v << ' ';
        //cout << endl;
        if (n % 2 == 0) {
            bool works = true;
            for (int v : cd) {
                if (v % 2 == 1) {
                    works = false;
                    break;
                }
            }
            if (!works) continue;
        } else {
            bool works = true;
            int c = 0;
            for (int v : cd) {
                if (v % 2 == 1) {
                    c++;
                    if (c > 1) {
                        works = false;
                        break;
                    }
                }
            }
            if (!works) continue;
        }

        if (cd[2] == 0 && cd[4] == 0 && cd[6] == 0 && cd[8] == 0) continue;
        res++;
    }
    cout << res << endl;
}

int main() {
    for (int i =1; i < 11; i++) {
        run(i);
    }
}
