#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, cases;
    cin >> n >> cases;

    vector<int> energy;
    for (int i=0; i < n; i++) {
        int en;
        cin >> en;
        energy.push_back(en);
    }

    vector<int> queries;
    int qmax = 0;
    for (int i=0; i < cases; i++) {
        int q;
        cin >> q;
        if (q > qmax) {
            qmax = q;
        }
        queries.push_back(q);
    }

    for (int i = n; i < qmax; i++) {
        int min_en = INT_MAX;
        for (int j = 0; j < energy.size() / 2; j++) {
            min_en = min(min_en, energy[j] + energy[energy.size() - j - 1]);
        }
        cout << " " << min_en << " "; 
        energy.push_back(min_en);
    }

    cout << endl << "RESULTS" << endl;

    for (int i=0; i < queries.size(); i++) {
        cout << energy[queries[i] - 1] << endl;
    }

    return 0;
}