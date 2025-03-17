#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    string s;
    cin >> s;
    string ns = s.substr(0, s.size() - 2);
    cout << ns << 'i' << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}