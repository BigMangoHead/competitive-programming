#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define vi vector<int>

struct Matrix{
    vector<vi> cell;
    int n,m;
    int mod;
    Matrix(int x, int y, int mod){
        n = x;
        m = y;
        cell.assign(n,vi(m,0));
        this->identity();
    }
    Matrix operator*(const Matrix& other){
        int x = n;
        int y = other.m;
        Matrix res(x,y, mod);
        if(m!=other.n){
            cout << "check indexing!\n";
        } else{
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    for(int k=0;k<m;k++){
                        //int inc = (cell[i][k]*other.cell[k][j]);
                        //res.cell[i][j]+=inc;
                        int inc = (cell[i][k]*other.cell[k][j])%mod;
                        res.cell[i][j]+=inc;
                        res.cell[i][j]%=mod;
                    }
                }
            }
        }
        return res;
    }
    void update(int i, int j, int num){
        if(i<n && j<m){
            cell[i][j] = num;
        } else{
            cout << "check indexing!\n";
        }
    }
    void identity(){
        if(n!=m){
            cout << "check indexing!\n";
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    cell[i][j] = 1;
                } else{
                    cell[i][j] = 0;
                }
            }
        }
    }
    void debug(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << cell[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void normalize(int mod){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cell[i][j]%=mod;
            }
        }
    }
    Matrix powMod(int p, int mod){
        Matrix res(n,m, mod);
        Matrix temp = *this;
        temp.normalize(mod);
        res.identity();
        if(n!=m){
            cout << "check indexing!\n";
        }
        while(p>0){
            if(p&1){
                res = res*temp;
            }
            p/=2;
            temp = temp*temp;
        }
        return res;
    }

    void print() {
        cout << cell[0][0] << ' ' << cell[0][1] << "\n";
        cout << cell[1][0] << ' ' << cell[1][1] << "\n";
        cout << "\n";
    }
};

struct segTree{
    vector<Matrix> tree;
    int n;
    int mod;
    segTree(vector<Matrix> &a, int mod){
        this->mod = mod;
        int _n = a.size();
        int log = 31-__builtin_clz(_n);
        log+=(__builtin_popcount(_n)>1);
        n = 1LL<<log;
        int num = n<<1LL;
        tree.assign(num, Matrix(2, 2, mod));
        for(int i=0;i<a.size();i++){
            tree[i+n] = a[i];
        }
        for(int i=n-1;i>=1;i--){
            tree[i] = tree[i*2]*tree[i*2+1];
        }
    }

    Matrix sum(int a, int b){
        Matrix resA = Matrix(2, 2, mod);
        Matrix resB = Matrix(2, 2, mod);
        a+=n; b+=n;
        while(a<=b){
            if(a&1) resA = resA*tree[a++];
            if(!(b&1)) resB = tree[b--]*resB;
            a>>=1; b>>=1;
        }
        return resA*resB;
    }
    void _replace(int i, Matrix x){
        int index = i+n;
        tree[index]=x;
        while(index>1){
            index>>=1LL;
            tree[index] = tree[index*2]*tree[index*2+1];
        }
    }
};

int main() {
    int r, n, m;
    cin >> r >> n >> m;

    vector<Matrix> mat(n, Matrix(2, 2, r));
    for (int i=0; i < n; i++) {
        for (int j=0; j < 2; j++) {
            for (int k=0; k < 2; k++) {
                int x;
                cin >> x;
                mat[i].update(j, k, x);
            }
        }
    }
    cout << "TEST" << endl;

    segTree res(mat, r);
    for (int i=0; i < m; i++) {
        cout << "TEST1" << endl;
        int a, b;
        cin >> a >> b;
        Matrix out = res.sum(a-1, b-1);
        cout << "TEST2" << endl;
        out.print();
    }
    cout << "TEST" << endl;
    
}