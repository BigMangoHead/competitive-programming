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
    
    int count = 0;
    for (int i = 0; i < s.size(); i++) {

        vector<int> hasAppeared(26, 0);
        hasAppeared[toInt(s[i])] = 1;

        for (int j=i + 1; j < s.size(); j++) {
            //cout << i << " " << j << " " << s.substr(i, j+1) << endl;
            if (hasAppeared[toInt(s[j])] == 0) {
                count++;
            } else if (s[j] == s[i]) {
                break;
            }
            hasAppeared[toInt(s[j])] = 1;
        }
    }

    cout << count;
    return 0;
    
}