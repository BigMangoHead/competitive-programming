#include <bits/stdc++.h>
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a(n-1);
    for (int i=0;i < n-1; i++) {
        cin >> a[i];
    }
    int end;
    cin >> end;
    sort(a.begin(), a.end());
    cout << end + a[n-2] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}