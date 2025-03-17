#include <iostream>
#include <vector>
using namespace std;
#include "/home/bigma/coding/comp/templates/algebra/matrix-static.cpp"
#include "/home/bigma/coding/comp/templates/number-theory/modint-simple.cpp"
#define ll long long

using llmatrix = StaticSquareMatrix<long long, 2>;
using modmatrix = StaticSquareMatrix<ModInt<100>, 2>;

void run() {
    matrix m;
    cin >> m;
    cout << m;
    m.transpose();
    cout << m;

    cout << m.pow(3);

    modmatrix m2;
    m2.vals[0][0] = 3;
    m2.vals[1][0] = 0;
    m2.vals[1][1] = 3;
    m2.vals[0][1] = 0;

    cout << m2.pow(5).vals[0][0].val;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
