//https://cses.fi/problemset/task/1617
#include <bits/stdc++.h>
 
using namespace std;
 
int modulo = 1e9 + 7;
 
long long binpow(long long a, long long b, long long modulo) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) {
            res *= a;
            res %= modulo;
        }
        a *= a;
        a %= modulo;
        b >>= 1;
    }
    return res;
}
 
int main() {
    int n;
    cin >> n;
    cout << binpow(2, n, modulo);
    return 0;
}
