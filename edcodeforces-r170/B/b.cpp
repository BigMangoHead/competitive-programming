#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
void run() {
    int n;
    cin >> n;
    vector<vector<int>> queries(n);
    int ma = 0;
    for (int i=0; i < n; i++) {
        vector<int> val(4);
        val[0] = i;
        cin >> val[1];
        queries[i] = val;
        ma = max(ma, val[1]);
    }


    for (int i=0; i < n; i++) {
        cin >> queries[i][2];
    }

    auto compA = [](vector<int> x, vector<int> y) {
        return x[1] < y[1];
    };
    sort(queries.begin(), queries.end(), compA);

    vector<int> results(n);

    vector<int> CA(ma + 1);
    vector<int> CB(ma + 1);
    
    vector<int>* C1 = &CA;
    vector<int>* C2 = &CB;

    int pos = 0;
    for (int i = 0; i <= ma; i++) { // loop over n from 0 to N-1 (inclusive)
        (*C1)[0] = 1;
        (*C1)[i] = 1;
        for (int k = 1; k < i; k++) // loop over k from 1 to n-1 (inclusive)
            (*C1)[k] = ((*C1)[k - 1] + (*C2)[k - 1]) % MOD;

        while (pos < queries.size() && queries[pos][1] == i) {
            queries[pos][3] = (*C1)[queries[pos][2]];
            pos++;
        }
        if (pos >= queries.size()) {
            break;
        }

        vector<int>* tmp = C2;
        C2 = C1;
        C1 = tmp;
    }

    auto compB = [](vector<int> x, vector<int> y) {
        return x[0] < y[0];
    };
    sort(queries.begin(), queries.end(), compB);
    for (auto & q : queries) {
        cout << q[3] << endl;
    }
}


int main(void) {
    run();
    return 0;
}