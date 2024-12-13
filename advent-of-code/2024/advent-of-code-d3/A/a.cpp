#include <iostream>
using namespace std;

const string sStart = "mul(";

int main(void) {
    string x;
    int sPos = 0;
    long long res = 0;
    string n1 = "";
    string n2 = "";
    while(getline(cin, x)) {
        for (auto & c : x) {
            if (sPos < 4) {
                if (c == sStart[sPos]) {
                    sPos++;
                } else {
                    sPos = 0;
                }
            } else {
                if ((int) (c-'0') >= 0 && (int) (c-'0') <= 9) {
                    if (sPos == 4) {
                        n1 += c;
                    } else {
                        n2 += c;
                    }
                } else if (c == ',' && sPos == 4) {
                    sPos++;
                } else if (c == ')' && sPos == 5) {
                    //clog << n1 << " " << n2 << endl;
                    res += stoll(n1) * stoll(n2);
                    sPos = 0;
                    n1 = "";
                    n2 = "";
                } else {
                    sPos = 0;
                    n1 = "";
                    n2 = "";
                }
            }
        }
        sPos = 0;
        n1 = "";
        n2 = "";
    }
    cout << res;
}