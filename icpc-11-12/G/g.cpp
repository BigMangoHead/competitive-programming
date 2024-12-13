#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int ntwo = pow(2, n);

    vector<int> bvals(ntwo);
    for (int i=0; i < ntwo; i++) {
        cin >> bvals[i];
    }

    vector<bool> res(ntwo, false);
    int vertexCount = 0;

    for (int i=0; i < n; i++) {
        int parCount = pow(2, i);
        for (int j=0; j < parCount; j++) {
            if (res[j] == true) continue;
            bool allEqual = true;

            bool reference = bvals[j];
            for (int k=j + parCount; k < ntwo; k += parCount) {
                if (bvals[k] != reference) {
                    allEqual = false;
                    break;
                }
            }

            if (allEqual) {
                for (int k=j; k < ntwo; k += parCount) {
                    res[k] = true;
                }
            }
            vertexCount++;
        }
    }

    for (int i=0; i < ntwo; i++) {
        if (!res[i]) vertexCount++;
    }

    cout << vertexCount;
}