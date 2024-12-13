#include <iostream>
using namespace std;

const string sStart = "mul(";
const string sStart2 = "do()";
const string sStart3 = "don't()";

int main(void) {
    string x;
    int sPos = 0;
    int wChoice = -1;
    long long res = 0;
    string n1 = "";
    string n2 = "";
    bool should = true;
    while(getline(cin, x)) {
        for (auto & c : x) {
            if (c == 'm') {
                wChoice = 1;
            } else if (c == 'd') {
                wChoice = 2;
            }
            if (c == 'm' || c == 'd') {
                sPos = 1;
                n1 = "";
                n2 = "";
                continue;
            }

            if (wChoice == 1) {
                if (sPos < 4) {
                    if (c == sStart[sPos]) {
                        sPos++;
                    } else {
                        sPos = 0;
                        wChoice = -1;
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
                        if (should) res += stoll(n1) * stoll(n2);
                        sPos = 0;
                        n1 = "";
                        n2 = "";
                        wChoice = -1;
                    } else {
                        sPos = 0;
                        n1 = "";
                        n2 = "";
                        wChoice = -1;
                    }
                }
            } else {
                if (sPos == 1) {
                    if (c == 'o') {
                        sPos++;
                    } else {
                        sPos = 0;
                        wChoice = -1;
                    }
                } else if (sPos == 2) {
                    if (c == 'n') {
                        wChoice = 4;
                        sPos++;
                    } else if (c == '(') {
                        wChoice = 3;
                        sPos++;
                    } else {
                        sPos = 0;
                        wChoice = -1;
                    }
                } else if (wChoice == 3) {
                    if (c == sStart2[sPos]) {
                        sPos++;
                    } else {
                        sPos = 0;
                        wChoice = -1;
                    }
                    if (sPos >= sStart2.size()) {
                        should = true;
                        wChoice = -1;
                        sPos = 0;
                    }
                } else if (wChoice == 4) {
                    if (c == sStart3[sPos]) {
                        sPos++;
                    } else {
                        sPos = 0;
                        wChoice = -1;
                    }
                    if (sPos >= sStart3.size()) {
                        should = false;
                        wChoice = -1;
                        sPos = 0;
                    }
                }
            }
        }
    }
    cout << res;
}