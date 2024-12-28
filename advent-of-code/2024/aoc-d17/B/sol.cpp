#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

string run(long long A) {
    long long B = 0;
    long long C = 0;
    vector<int> program = {2,4,1,3,7,5,0,3,1,4,4,7,5,5,3,0};

    auto combo = [&](int x) {
        if (x < 4) return (long long) x;
        if (x == 4) return A;
        if (x == 5) return B;
        if (x == 6) return C;
        return 0LL;
    };

    vector<function<pair<int, int>(int x)>> ops;
    ops.push_back([&](int x) {
        int v = combo(x);
        A = A / (pow(2, v));
        return make_pair(-1, 0);
    });
    ops.push_back([&](int x) {
        B = B ^ x;
        return make_pair(-1, 0);
    });
    ops.push_back([&](int x) {
        B = combo(x) & 7;
        return make_pair(-1, 0);
    });
    ops.push_back([&](int x) {
        if (A == 0) return make_pair(-1, 0);

        return make_pair(2, x);
    });
    ops.push_back([&](int x) {
        B = B ^ C;
        return make_pair(-1, 0);
    });
    ops.push_back([&](int x) {
        return make_pair(1, combo(x) & 7);
    });
    ops.push_back([&](int x) {
        int v = combo(x);
        B = A / (pow(2, v));
        return make_pair(-1, 0);
    });
    ops.push_back([&](int x) {
        int v = combo(x);
        C = A / (pow(2, v));
        return make_pair(-1, 0);
    });

    int op_pointer = 0;
    string output = "";
    while (op_pointer+1 < program.size()) {
        pair<int, int> res = ops[program[op_pointer]](program[op_pointer+1]);
        if (res.first == 1) {
            output += to_string(res.second);
            output += ',';
        } else if (res.first == 2) {
            op_pointer = res.second;
            op_pointer -= 2;
        }
        op_pointer+= 2;
    }

    return output;
}

int main() {
    long long A = 0;
    while (true) {
        if (run(A) == "2,4,1,3,7,5,0,3,1,4,4,7,5,5,3,0,") {
            cout << A << endl;
            return 0;
        }
    }
}