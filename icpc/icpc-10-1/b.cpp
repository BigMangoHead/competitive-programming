#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int k;
    cin >> k;

    unordered_map<string, int> images1;
    int fails = 0;
    int successes = 0;
    for (int i=0; i < k; i++) {
        int a, b;
        string x, y;
        cin >> a >> b;
        cin >> x >> y;

        if (x == y) {
            fails++;
        } else {
            if (images1.find(x) != images1.end() && images1[x] != a+1) {
                successes++;
            } else {
                images1[x] = a + 1;
            }

            if (images1.find(y) != images1.end() && images1[y] != b+1) {
                successes++;
            } else {
                images1[y] = b + 1;
            }
        }
    }

    if (fails + successes == n / 2 - 1) {
        cout << n / 2 - fails;
    } else if (images1.size() == n / 2) {
        cout << n / 2 - fails;
    } else {
        cout << successes;
    }

    return 0;
}