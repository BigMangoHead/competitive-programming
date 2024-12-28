#include <bits/stdc++.h>
using namespace std;

bool attempt(long long turn, vector<long long> dmg, vector<long long> cd, long long hp) {

    turn = turn-1;
    long long damage = 0;
    for (int i=0; i<dmg.size(); i++) {
        damage += dmg[i]*(turn/cd[i]+1);
    }

    return damage >= hp;
}

void run() {
    long long hp;
    long long n;
    cin >> hp >> n;
    vector<long long> dmg(n);
    vector<long long> cd(n);
    for (int i = 0; i < n; i++) {
        cin >> dmg[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cd[i];
    }
    long long high = 1;
    long long low = 1;
    while (!attempt(high,dmg,cd,hp)) {
        high = 2*high;
    }

    while (true) {
        long long turn = (high+low+1)/2;
        bool temp = attempt(turn,dmg,cd,hp);
        if (!temp) {
            low = turn;
        }
        else {
            high = turn;
        }
        if (!attempt(high-1,dmg,cd,hp) && attempt(high,dmg,cd,hp)) {break;}

    }
    cout << high << endl;
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