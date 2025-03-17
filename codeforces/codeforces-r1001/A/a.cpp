#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void run() {
    string s;
    cin >> s;
    int count =  0;
    for (auto& c : s) {
        if (c == '1') count++;
    }
    cout << count << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1;
        run();
    }
}