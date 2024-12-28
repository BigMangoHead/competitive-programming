#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void run() {
    vector<long long> input;
    long long k;
    for (int i=0; i < 3; i++) {
        long long x;
        cin >> x;
        input.push_back(x);
    }
    cin >> k;
    sort(input.begin(), input.end());
    long long x = input[0];
    long long y = input[1];
    long long z = input[2];

    vector<int> primes;
    for (int i=2; i < 2000; i++) {
        bool prime = true;
        for (auto & p : primes) {
            if (i % p == 0) {
                prime = false;
            }
        }
        if (prime) primes.push_back(i);
    }

    vector<int> factor(2000);


    
}

void run2() {
    vector<long long> input;
    long long k;
    for (int i=0; i < 3; i++) {
        long long x;
        cin >> x;
        input.push_back(x);
    }
    cin >> k;
    sort(input.begin(), input.end());
    long long x = input[0];
    long long y = input[1];
    long long z = input[2];

    long long ma = 0;
    for (int a=1; a <= x; a++) {
        for (int b=1; b <= y; b++) {
            if (k % b != 0) {
                continue;
            }
            long long c = k;
            c /= b;
            if (c % a != 0) {
                continue;
            }
            c /= a;
            
            if (c > z) continue;
            long long res = (x - a + 1)*(y - b + 1)*(z - c + 1);
            ma = max(res, ma);
        }
    }

    cout << ma << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run2();
    } 
}