#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
 
int main()
{
    int n = 100000; // for example
    int i, j;
    long long sum = 0;
 
    for (i = 1; i <= n; i++) {
        sum += (n / i);
    }

    cout<<"The sum of the number of divisors from 1 to "<<n<<" is "<<sum<<endl;
    return 0;
}