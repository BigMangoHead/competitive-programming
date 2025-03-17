#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long

void run() {
    map<int, int> a;
    int n, k;
    cin >> n >> k;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    } 

    pmr::vector<int> b;
    for (auto & v : a) {
        b.push_back(v.second);
    }
    sort(b.begin(), b.end());
    int sum = 0;
    int count = b.size();
    for (int i=0; i < b.size()-1; i++) {
        sum += b[i];
        if (sum > k) {
            break;
        }
        count--;
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        // clog << "Case " << i+1;
        run();
    } 
}