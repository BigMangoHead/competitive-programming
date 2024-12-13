#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Drone {
    int start_pos;
    int velo;
    int next;
    int prev;
    Drone (int start, int vel, int prev, int next) {
        start_pos = start;
        vel = velo;
    }
};

int main(void) {

    int n;
    cin >> n;

    vector<Drone> drones(n);
    for (int i =0; i < n; i++) {
        pair<int, int> drone;
        cin >> drone.first >> drone.second;
        drones[i] = drone;
    }



    return 0;
}