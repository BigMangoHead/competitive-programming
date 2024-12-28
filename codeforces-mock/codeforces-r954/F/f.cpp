#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;

struct Node {
    int containedCount = 1;
    vector<Node*> neighbors;
    Node* prevInPath;
};

void run() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    
    for (int i=0; i < n; i++) {
        run();
    }
}