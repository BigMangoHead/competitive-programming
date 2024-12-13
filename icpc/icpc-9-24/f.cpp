#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void) {
    vector<vector<string>> names;
    unordered_map<string, int> hasAppeared;
    string s;
    while (cin >> s) {
        if (s == "0") {
            break;
        }
        hasAppeared[s]++;
        string s2;
        cin >> s2;
        vector<string> name = {s, s2};
        names.push_back(name);
    }

    auto comp = [] (vector<string> a, vector<string> b) {
        if (a[1] == b[1]) {
            return (a < b);
        } else if (a[1] < b[1]) {
            return true;
        } else {
            return false;
        }
    };

    sort(names.begin(), names.end(), comp);

    for (auto & name : names) {
        cout << name[0];
        //cout << endl << hasAppeared[name[0]] << endl;
        if (hasAppeared[name[0]] > 1) {
            cout << " " << name[1];
        }
        cout << endl;
    }


    return 0;
}