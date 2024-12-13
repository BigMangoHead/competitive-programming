#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    string topicstring;
    getline(cin, topicstring);
    int topcount = 0;
    unordered_map<string, int> toppos;
    string curstring = "";
    int num = 0;
    for (int i=0; i < topicstring.size(); i++) {
        if (topicstring[i] == ' ') {
            topcount++;
            toppos[curstring] = num;
            num++;
            curstring = "";
        } else {
            curstring += topicstring[i];
        }
    }
    toppos[curstring] = num;
    topcount++;

    int songcount;
    cin >> songcount;
    vector<vector<string>> songs(songcount, vector<string>(topcount));

    for (int i=0; i < songcount; i++) {
        for (int j=0; j < topcount; j++) {
            cin >> songs[i][j];
        }
    }

    int pos = 0;
    auto comp = [&](const vector<string> & a,const vector<string> & b) {
        return a[pos] < b[pos];
    };

    int sorts;
    cin >> sorts;
    for (int i=0; i < sorts; i++) {
        string top;
        cin >> top;
        pos = toppos[top];
        stable_sort(songs.begin(), songs.end(), comp);
        cout << topicstring << endl;
        for (int j=0; j < songs.size(); j++) {
            for (int k=0; k < topcount; k++) {
                cout << songs[j][k];
                if (k != topcount-1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}