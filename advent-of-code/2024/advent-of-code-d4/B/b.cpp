#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string ln;
    vector<string> data;
    while (cin >> ln) {
        data.push_back(ln);
    }

    int res = 0;
    for (int i=1; i < data.size()-1; i++) {
        for (int j=1; j < data[i].size()-1; j++) {
            if (data[i][j] == 'A') {
                if (data[i-1][j-1] == 'M' && data[i+1][j+1] == 'S') {
                    
                } else if (data[i-1][j-1] == 'S' && data[i+1][j+1] == 'M') {

                } else {
                    continue;
                }

                if (data[i+1][j-1] == 'M' && data[i-1][j+1] == 'S') {
                    
                } else if (data[i+1][j-1] == 'S' && data[i-1][j+1] == 'M') {

                } else {
                    continue;
                }
                res++;
                    
            }
        }
    }
    cout << res;
}