#include <iostream>
#include <vector>
using namespace std;
#define ll long long



struct segTree{
    vector<int> tree;
    int n;
    segTree(vector<int> &a){
        int _n = a.size();
        int log = 31-__builtin_clz(_n);
        log+=(__builtin_popcount(_n)>1);
        n = 1LL<<log;
        int num = n<<1LL;
        tree.assign(num,0);
        for(int i=0;i<a.size();i++){
            tree[i+n] = a[i];
        }
        for(int i=n-1;i>=1;i--){
            tree[i] = tree[i*2]+tree[i*2+1];
        }
    }
    int sum(int a, int b){
        int res = 0;
        a+=n; b+=n;
        while(a<=b){
            if(a&1) res+=tree[a++];
            if(!(b&1)) res+=tree[b--];
            a>>=1; b>>=1;
        }
        return res;
    }
    void update(int i, int x){
        int index = i+n;
        tree[index]+=x;
        while(index>1){
            index>>=1LL;
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
    void _replace(int i, int x){
        int index = i+n;
        tree[index]=x;
        while(index>1){
            index>>=1LL;
            tree[index] = tree[index*2]+tree[index*2+1];
        }
    }
};

int main(void) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> v(n, 0);
    segTree tree(v);
    vector<int> res(n);

    for (int i=n-1; i >= 0; i--) {
        int low = 0;
        int high = n-1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            int s = (n-1 - mid) - tree.sum(mid, n-1);

            if (s >= a[i]) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        tree.update(low, 1);
        res[i] = low;
    }

    for (auto& v : res) {
        cout << v +1  << ' ';
    }
}