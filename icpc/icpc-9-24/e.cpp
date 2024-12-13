#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {
    while (true) {
        int rot;
        cin >> rot;
        if (rot == 0) {
            return 0;
        }
        string s;
        cin >> s;

        string result = "";
        for (int i=s.size() - 1; i >= 0; i--) {
            char chr = s[i];
            for (int k=0; k < rot; k++) {
                if (chr == '.') {
                    chr = 'A';
                } else if (chr == 'Z') {
                    chr = '_';
                } else if (chr == '_') {
                    chr = '.';
                } else {
                    chr = (char) ((int) chr + 1);
                }
            }
            result += chr;
        }
        cout << result << endl;
    }
}