#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

bool isPowOfTwo(int a) {
    //cout << a << endl;
    if (a == 0) {
        return false;
    }
    return (a & (a-1)) == 0;
}

int main(void) {

    string s;
    cin >> s;

    int count = 0;
    for (auto & chr : s) {
        if (chr == '(') {
            count ++;
        }
    }

    vector<string> result;
    for (int i=1; i < (int) (pow(2, count) + 0.5); i++) {
        string tmp = s;
        int rcount = 0;
        int lcount = 0;
        for (int j=0; j < tmp.size(); j++) {
            if (tmp[j] == '(') {
                if (isPowOfTwo(i & (1 << lcount))) {
                    tmp.erase(tmp.begin() + j);
                    j--;
                };

                lcount++;
            } else if (tmp[j] == ')') {
                // CHECK
                if (isPowOfTwo(i & (1 << count - rcount - 1))){
                    tmp.erase(tmp.begin() + j);
                    j--;
                } 
                    

                rcount ++;
            }
        }
        //cout << endl;
        result.push_back(tmp);

    }
    //cout << endl << "RESULT:" << endl;
    sort(result.begin(), result.end());
    for (string s : result) {
        cout << s << endl;
    }

    return 0;

}
