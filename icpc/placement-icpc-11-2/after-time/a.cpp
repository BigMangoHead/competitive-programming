#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int index;
    Node* prev;
};

class TimeLine {
    public:
        Node* currNode;
        double endDrinkPos; // How far to travel before coffee is completely consumed
        double currPos;
        double timeNotDrinking; // How much time prior to current position

        TimeLine(const double & untilDoneDist, const int & firstShopPos) {
            currNode = new Node();
            currNode->prev = nullptr;
            currNode->index = 0;

            timeNotDrinking = 0.0;
            currPos = firstShopPos;
            endDrinkPos = untilDoneDist + currPos;
        }
};

int main(void) {
    long long l;
    int a, b, t, r;
    cin >> l >> a >> b >> t >> r;
    double untilDoneDist = a * t + b * r;

    int n;
    cin >> n;
    vector<long long> cpos(n);
    for (int i=0; i < n; i++) {
        cin >> cpos[i];
    }

    list<TimeLine> realities;
    realities.push_front(TimeLine(untilDoneDist, cpos[0]));

    double prevBestNotDrinking = 0;
    int prevBestIndex = 0;
    for (int i=1; i < n; i++) { // Index of current coffee stand
        double bestNotDrinking = -1;

        vector<int> toRemove; // Store all timelines to be updated
        int toNotRemove; // Remember the best one

        for (auto it = realities.begin(); it != realities.end(); it++) {
            if (cpos[i] >= it->endDrinkPos) {
                if (bestNotDrinking == -1 || bestNotDrinking > it->)
            }


        }
    }

}


