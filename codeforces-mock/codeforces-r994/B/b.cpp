#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char fixed = '0';
    for (int i=0; i < n; i++) {
        if (s[i] == '.') continue;
        if (i == 0 && s[i] == 's') continue;
        if (i == n-1 && s[i] == 'p') continue;

        if (fixed == '0') {
            fixed = s[i];
        } else if (fixed != s[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        run();
    }
}