#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void run() {
    int n;
    cin >> n;
    int imp = -1;
    for (int i=0; i < n - 1; i+=2) {
        cout << "? " << i+1 << " " << i+2 << endl;
        cout.flush();
        int res1;
        cin >> res1;

        cout << "? " << i+2 << " " << i+1 << endl;
        cout.flush();
        int res2;
        cin >> res2;

        if (res1 != res2) {
            imp = i + 1;
            break;
        }
    }
    if (imp == -1) {
        cout << "! " << n << endl;
        cout.flush();
        return;
    }

    int quest;
    if (imp == 1) {
        quest = 3;
    } else {
        quest = 1;
    }

    cout << "? " << imp << " " << quest << endl;
    cout.flush();
    int res1;
    cin >> res1;
    cout << "? " << quest << " " << imp << endl;
    cout.flush();
    int res2;
    cin >> res2;

    if (res1 == res2) {
        cout << "! " << imp + 1 << endl;
    } else {
        cout << "! " << imp << endl;
    }
    cout.flush();
}


int main(void) {
    int test_cases;
    cin >> test_cases;
    for (int i=0; i < test_cases; i++) {
        run();
    }
    return 0;
}