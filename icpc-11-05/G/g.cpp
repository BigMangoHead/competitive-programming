#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(void) {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> m(r, vector<int>(c));
    for (int i=0; i < r; i++) {
        string s;
        cin >> s;
        for (int j=0; j < c; j++) {
            m[i][j] = s[j];
        }
    }

    vector<vector<int>> onesLeft(r, vector<int>(c)); // Including self
    vector<vector<int>> onesAbove(r, vector<int>(c)); // Include self
    for (int i=0; i < r; i++) {
        int count = 0;
        for (int j=0; j < c; j++) {
            count += m[i][j];
            onesLeft[i][j] = count;
        }
    }
    for (int j=0; j < c; j++) {
        int count = 0;
        for (int i=0; i < r; i++) {
            count += m[i][j];
            onesAbove[i][j] = count;
        }
    }

    // Matrix stores the least swaps required to get to the given position
    // Each array is of the form (least swaps possible), (length of ones to left, not including self), (length of ones above, not including self)
    vector<vector<array<int, 3>>> dp(r, vector<array<int, 3>>(c)); 

    // Calculate values on left and top edge
    for (int i=0; i < r; i++) {
        dp[i][0] = {i+1 - onesAbove[i][0], 0, i};
    }
    for (int i=0; i < c; i++) {
        dp[0][i] = {i+1 - onesAbove[i][0], 0, i};
    }
    dp[0][0][0] = 1 - m[0][0];
    dp[0][0][1] = 1;
    dp[0][0][2] = 1;
    for (int d=1; d < r+c-1; d++) {
        
    }



}