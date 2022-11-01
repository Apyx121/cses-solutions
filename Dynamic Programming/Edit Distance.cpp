//https://cses.fi/problemset/task/1639
#include <bits/stdc++.h>
 
using namespace std;
 
int dp[5005][5005];
 
int main() {
    string s, t; cin >> s >> t;
    for(int i = 0; i <= 5000; i++) {
        for(int j = 0; j <= 5000; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i <= 5000; i++) {
        dp[i][0] = i;
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= s.size(); i++) {
        for(int j = 1; j <= t.size(); j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            } else {
                dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]);
            }
            dp[i][j] = min(dp[i][j], 1+dp[i-1][j]);
            dp[i][j] = min(dp[i][j], 1+dp[i][j-1]);
        }
    }
    cout << dp[s.size()][t.size()];
    return 0;
}
