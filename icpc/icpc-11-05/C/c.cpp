#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(void) {

    int n, k;
    cin >> n >> k;
    vector<ll> candy(n);
    ll full_sum = 0;
    for (int i=0; i < n; i++) {
        cin >> candy[i];
        full_sum += candy[i];
    }

    sort(candy.begin(), candy.end());

    ll sum = 0;
    for (int i=0; i <= n-k; i++) {
        sum += candy[i];
    }

    ll moves = sum;
    int numsInGroup = 2;
    for (int i=n-k+1; i < n; i++) {
        sum += candy[i];
        moves = min(moves, sum / numsInGroup);
        numsInGroup++;
    }

    if (moves >= candy[n-1] - 1) {
        cout << (k - (full_sum % k)) % k;
    } else {
        ll remaining_sum = full_sum - moves*k;
        ll total_creating = (candy[n-1] - moves)*k;
        cout << total_creating - remaining_sum;
    }
}