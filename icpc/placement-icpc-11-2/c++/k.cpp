#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;

bool allPossible(string s, set<char>& v, int i, int x) {
    set<char> v2 = set<char>(v);
    for (int i=0; i<s.size(); i++) {
        v2.erase(s[i]);
        if (v2.size() == 0) {
            v2 = set<char>(v);
            x--;
            if (x==0) return true;
        }
    }
    return false;
}

bool isCorrect(unordered_map<char, vector<int>>& m, string q, string & s) {
    int start = 0;
    if (s[0] == q[0]) {
        start = 1;
    }
    int ndl = 0;
    for (int i=start; i<q.length(); i++) {
        ndl = m[q[i]][ndl];
        if (ndl == -1) return false;
    }
    return true;
}

int main(void) {
    string vold, s;
    int n;
    cin >> vold >> s;
    cin >> n;
    vector<string> inputs(n);
    for (int i=0; i < n; i++) {
        cin >> inputs[i];
    }
    set<char> v;
    for (int i=0; i < vold.size(); i++) {
        v.insert(vold[i]);
    }

    unordered_map<char, vector<int>> m;
    for (int voldi=0; voldi<vold.length(); voldi++) {
        char v0 = vold[voldi];
        vector<int> l = vector<int>(s.length());
        int ndl = -1;
        for (int i = s.length()-1; i>=0; i--) {
            l[i] = ndl;
            if (s[i] == v0) {
                ndl = i;
            }
        }
        m[v0] = l;
    }

    int low = 0;
    int high = s.length()+1;
    while (high-low > 1) {
        int mid = (low+high)/2;
        if (allPossible(s, v, 0, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    for (int ini=0; ini<inputs.size(); ini++) {
        string q = inputs[ini];
        if (q.length() != high) {
            cout << 0 << endl;
            continue;
        }
        if (!isCorrect(m, q, s)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
