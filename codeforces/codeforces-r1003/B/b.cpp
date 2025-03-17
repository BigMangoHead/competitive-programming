#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    string s;
    cin >> s;
    int pos = -1;
    for (int i=0; i < s.size()-1; i++) {
        if (s[i] == s[i+1]) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << s.size() << "\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}