#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int a;
    cin >> a;

    for (int b = 0; b < a; b++) {
        int n, dur, jobC;
        cin >> n >> dur >> jobC;

        vector<int> starts(n, 0);
        vector<int> ends(n + 1, 0);
        for (int i=0; i < jobC; i++) {
            int start, end;
            cin >> start >> end;
            starts[start - 1] ++;
            ends[end - 1]++;
        }

        int count = 0;
        for (int i=0; i < dur-1; i++) {
            count += starts[i];
        }

        int minim = INT_MAX;
        int min_i = 0;
        int maxim = 0;
        int max_i = 0;
        for (int i=dur-1; i < n; i++) {

            count += starts[i];
            if (count < minim) {
                minim = count;
                min_i = i - dur + 1;
            } 
            if (count > maxim) {
                maxim = count;
                max_i = i - dur + 1;
            }

            count -= ends[i - dur + 1];
        }

        cout << max_i + 1 << " " << min_i + 1 << endl;
    }
}