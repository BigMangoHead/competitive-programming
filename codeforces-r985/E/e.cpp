#include <climits>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct PrimeChecker {
    unordered_map<int, bool> isPrime;

    void preCal() {
        for (int i=2; i < 4*pow(10, 5); i++) {
            bool prime = true;
            for (int j=2; j <= sqrt(i); j++) {
                if (!checkPrime(j)) continue;
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                isPrime[i] = true;
            }
        }
    }

    bool checkPrime(int p) {
        if (isPrime.count(p)) return true;
        return false;
    }
};

int getSmallestFactor(int num, PrimeChecker & p) {
    for (int i=2; i < num; i++) {
        if (p.checkPrime(i)) {
            if (num % i == 0) {
                return i;
            }
        }
    }
    return -1;
}

void run(PrimeChecker & p) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i < n; i++) cin >> nums[i];

    int prime = 0;
    for (int i=0; i < n; i++) {
        if (p.checkPrime(nums[i])) {
            prime = nums[i];
        }
    }
    if (prime == 0) {
        cout << 2 << endl;
        return;
    }

    bool possible = true;
    for (int i=0; i < n; i++) {
        if (nums[i] == prime) continue;

        if (p.checkPrime(nums[i])) {
            possible = false;
            break;
        }

        if (nums[i] % prime != 0) {
            if (nums[i] < 2*prime) {
                possible = false;
                break;
            } else if (nums[i] > 4*prime) {
                continue;
            } else {
                if (nums[i] % 2 == 0) continue;
                
                int x = getSmallestFactor(nums[i], p);
                int rem = prime - (prime % x);
                if (nums[i] < 2*(prime + rem)) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if (possible) cout << prime << endl;
    else cout << -1 << endl;
}


int main(void) {
    PrimeChecker p = PrimeChecker();
    p.preCal();
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run(p);
    }
}