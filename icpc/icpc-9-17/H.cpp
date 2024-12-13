#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int toInt(char & chr) {
    return (int) chr - 97;
}

int main(void) {
    string s;
    cin >> s;
    vector<int> nextAppear(s.size(), INT_MAX); //nextAppearance
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.size(); i++) {
        char chr = s[i];

        if (lastSeen[toInt(chr)] != -1) {
            nextAppear[lastSeen[toInt(chr)]] = i;
        }
        lastSeen[toInt(chr)] = i;
    }

    int rpos;
    int maxr;
    int count = 0;
    for (int lpos=0; lpos < s.size(); lpos++) {
        maxr = nextAppear[lpos];
        
        rpos = lpos + 1;
        while (rpos < maxr && rpos < s.size()) {
            cout << lpos << " " << rpos << " " << nextAppear[rpos] << endl;
            count++;
            maxr = min(maxr, nextAppear[rpos]);
            rpos++;
        }
    }

    cout << count;
    return 0;
    
}