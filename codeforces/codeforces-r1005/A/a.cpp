#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int moves = 0;
    char prev = '0';
    for (auto& c : s) {
        if (c != prev) {
            prev = c;
            moves++;
        }
    }
    cout << moves << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}