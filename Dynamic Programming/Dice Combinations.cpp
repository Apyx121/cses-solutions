//https://cses.fi/problemset/task/1633/
#include <bits/stdc++.h>

using namespace std;

const int modulo = 1e9 + 7;
const int nmax = 1e6;

long long dp[nmax+5];

int main() {
    int n; cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                dp[i] += dp[i-j];
            }
        }
        dp[i] %= modulo;
    }
    cout << dp[n];
    return 0;
}
