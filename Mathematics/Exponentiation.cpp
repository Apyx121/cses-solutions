//https://cses.fi/problemset/task/1095
#include <bits/stdc++.h>
 
using namespace std;
 
const int modulo = 1e9 + 7;
 
long long binpow(long long a, long long b, long long mod) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}
 
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        cout << binpow(x, y, modulo) << "\n";
    }
    return 0;
}
