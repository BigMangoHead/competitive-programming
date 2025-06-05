#include <iostream>
#include <vector>
using namespace std;
#include "/home/bigma/coding/comp/templates/algebra/square-matrix-static.cpp"
//#include "/home/bigma/coding/comp/templates/number-theory/modint-simple.cpp"
#define ll long long

using llmatrix = StaticSquareMatrix<long long, 2>;
//using modmatrix = StaticSquareMatrix<ModInt<100>, 2>;

void run() {
    matrix m;
    cin >> m;
    cout << m;
    m.transpose();
    cout << m;

    cout << m.pow(3);

    cout << m[1][1] << endl;
    cout << m.pow(3)[1][1] << endl;
}

int main(void) {
    int n;
    cin >> n;
    for (int i=0; i < n;i++) {
        // clog << "Case " << i+1 << endl;
        run();
    }
}
