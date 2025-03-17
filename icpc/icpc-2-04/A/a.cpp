#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define ll long long

int main(void) {
    map<char, string> trans;
    trans['a'] = "@";
    trans['b'] = "8";
    trans['c'] = "(";
    trans['d'] = "|)";
    trans['e'] = "3";
    trans['f'] = "#";
    trans['g'] = "6";
    trans['h'] = "[-]";
    trans['i'] = "|";
    trans['j'] = "_|";
    trans['k'] = "|<";
    trans['l'] = "1";
    trans['m'] = "[]\\/[]";
    trans['n'] = "[]\\[]";
    trans['o'] = "0";
    trans['p'] = "|D";
    trans['q'] = "(,)";
    trans['r'] = "|Z";
    trans['s'] = "$";
    trans['t'] = "']['";
    trans['u'] = "|_|";
    trans['v'] = "\\/";
    trans['w'] = "\\/\\/";
    trans['x'] = "}{";
    trans['y'] = "`/";
    trans['z'] = "2";
    string s;
    getline(cin, s);

    string res = "";
    for (auto& c : s) {
        if ((int)c - (int)'a' >= 0 && (int)c - (int)'a' <= 25 ) {
            res += trans[c];

        }
        else if ((int)c - (int)'A' >= 0 && (int)c - (int)'A' <= 25) {
            res += trans[(char) ((int)c - (int)'A' + (int)'a')];
        }
        else {
            res += c;
        }
    }
    cout << res << endl;
}