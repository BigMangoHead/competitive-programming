#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    string n1, n2;
    cin >> n1 >> n2;

    int n;
    cin >> n;

    string game;
    bool works = true;
    for (int i=0; i < n; i++) {
        getline(cin, game);

        // Check validity of int size
        if (game.size() != 7 && game.size() != 11) {
            cout << "ne" << endl;
            continue;
        }
        if (game.size() == 11 && game[1] != ':') {
            cout << "ne" << endl;
            continue;
        }
        
        int times = game.size() % 3 + 1;
        for (int i=0; i < times; i++) {
            int p1, p2;
            p1 = game[1 + 4*i] - '0';
            p2 = game[3 + 4*i] - '0';

            if (n1 == "federer" && p1 < p2) {
                works = false;
                break;
            }
            if (n2 == "federer" && p2 < p1) {
                works = false;
                break;
            }

            if (p1 == 6) {
                if (p2 == 6 && i != 2) {
                    works = false;
                    break;
                } else if (p2 > 7) {
                    works = false;
                    break;
                } else {
                    continue;
                }
            }
            if (p2 == 6) {
                if (p1 > 7) {
                    works = false;
                    break;
                } else {
                    continue;
                }
            }

            works = false;
            break;
        }
        if (!works) {
            cout << "ne" << endl;
        } else {
            cout << "da" << endl;
        }
    }

    return 0;
}