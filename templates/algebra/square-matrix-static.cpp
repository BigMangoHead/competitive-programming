// Named "static" because size must be determined at compile time.
template <typename T, int size>
struct StaticSquareMatrix {
    T vals[size][size] = {}; // row, column

    // NOTE: For large matrix multiplication of INT/LL, it is much more efficient 
    // (3x for 1000x1000) to transpose the second matrix before multiplying. 
    // const modifier needs to be removed to do this.
    StaticSquareMatrix operator*(const StaticSquareMatrix& other) {
        StaticSquareMatrix res;
        for (int i=0; i < size; i++) {
            for (int j=0; j < size; j++) {
                for (int k=0; k < size; k++) {
                    res.vals[i][j] += vals[i][k]*other.vals[k][j];
                }
            }
        }
        return res;
    }

    StaticSquareMatrix operator*=(const StaticSquareMatrix& other) {
        vals = ((*this)*other).vals;
    }

    StaticSquareMatrix operator*(const T& scalar) {
        StaticSquareMatrix res;
        for (int i=0; i < size; i++) {
            for (int j=0; j < size; j++) {
                res.vals[i][j] = vals[i][j]*scalar;
            }
        }
    }

    StaticSquareMatrix operator+(const StaticSquareMatrix& other) {
        StaticSquareMatrix res;
        for (int i=0; i < size; i++) {
            for (int j=0; j < size; j++) {
                res[i][j] = vals[i][j] + other.vals[i][j];
            }
        }
    }

    int* operator[](int pos) {
        return vals[pos];
    }

    friend ostream& operator<<(ostream& os, const StaticSquareMatrix& m) {
        for (int i=0; i < size; i++) {
            for (int j=0; j < size; j++) {
                os << m.vals[i][j] << ' ';
            }
            os << "\n";
        }
        return os;
    }

    friend istream& operator>>(istream& is, StaticSquareMatrix& m) {
        for (int i=0; i < size; i++) {
            for (int j=0; j < size; j++) {
                is >> m.vals[i][j];
            }
        }
        return is;
    }

    // NOTE: This assumes that T(1) is the additive identity
    void identity() {
        for (int i=0; i < size; i++) {
            vals[i][i] = T(1);
        }
    }

    void transpose() {
        for (int i=0; i < size; i++) {
            for (int j=i+1; j < size; j++) {
                swap(vals[i][j], vals[j][i]);
            }
        }
    }

    StaticSquareMatrix pow(int p) {
        StaticSquareMatrix res;
        StaticSquareMatrix temp = *this;
        res.identity();
        while (p > 0) {
            if (p & 1) {
                res = res*temp;
            }
            p /= 2;
            if (p > 0) temp = temp*temp;
        }
        return res;
    }
};

using matrix = StaticSquareMatrix<int, 2>; // 2x2 integer matrix

