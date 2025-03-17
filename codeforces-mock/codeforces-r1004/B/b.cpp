#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

void run() {
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    bool works = true;
    while (pq.size() > 0) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if (x != y) {
            works = false;
            break;
        }
        int count = 0;
        while (pq.size() > 0 && pq.top() == x) {
            pq.pop();
            count++;
        }
        for (int i=0; i < count; i++) {
            pq.push(x+1);
        }
    }
    if (works) cout << "YES\n";
    else cout << "NO\n";
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n; i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
