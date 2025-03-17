#include <iostream>
#include <vector>
using namespace std;
#define ll long long

bool check(string& s) {
    int oc = 0;
    for (auto& c : s) {
        if (c == '(') oc++;
        else oc--;
        if (oc < 0) return false;
    }
    return true;
}

int main() {
    int oc = 0, cc = 0;

    string s;
    cin >> s;
    for (auto & c : s) {
        if (c == ')') cc++;
        else if (c == '(') oc++;
    }
    if (check(s)) {
        cout << "possible" << endl;
        return 0;
    }
    if (s.size() % 2 == 1) {
        cout << "impossible" << endl;
        return 0;
    }

    int o = 0;
    int ccc = cc;
    int breakf = 0;
    for (int i=0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(') o++;
        else {
            o--;
            ccc--;
        }
        if (o < 0) {
            breakf = i;
            break;
        } else if (o > ccc) {
            breakf = i;
            break;
        }
    }
    o = 0;
    ccc = oc;
    int breakb = 0;
    for (int i=s.size()-1; i >= 0; i--) {
        char c = s[i];
        if (c == ')') o++;
        else {
            o--;
            ccc--;
        }
        if (o < 0) {
            breakb = i;
            break;
        } else if (o > ccc) {
            breakb = i;
            break;
        }
    }





}