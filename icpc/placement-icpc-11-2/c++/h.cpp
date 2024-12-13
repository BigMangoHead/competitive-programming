#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    int h, n, m;
    cin >> h >> n >> m;
    int needed = 1 + 2*h*(h-1);
    int curr = n + 2*m;
    int rem = needed - curr;

    if (rem < 0) {
        if (n == 0) rem = 1;
        else if (n == 1) rem = 0;
        else rem = 0;
    }
    
    cout << rem % 2 << " " << rem / 2 << endl;

    return 0;
}