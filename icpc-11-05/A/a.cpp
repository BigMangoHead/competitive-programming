#include <iostream>
#include <vector>
using namespace std;

int main(void) {

    string input;
    cin >> input;
    vector<vector<int>> letters(3, vector<int>(input.size(), 0));
    letters[input[0] - 65][0] = 1;
    for (int i=1; i < input.size(); i++) {
        letters[0][i] = letters[0][i-1];
        letters[1][i] = letters[1][i-1];
        letters[2][i] = letters[2][i-1];
        letters[((int) input[i]) - 65][i]++;
    }

    int ma = 0;
    for (int i=0; i < letters[0].size(); i++) {
        int dist = max(abs(letters[0][i] - letters[1][i]), abs(letters[0][i] - letters[2][i]));
        dist = max(dist, abs(letters[1][i] - letters[2][i]));
        ma = max(ma, dist);
    }

    cout << ma;
}