//https://cses.fi/problemset/task/2216/
#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;

int v[nmax+5], b[nmax+5];

int main() {
    int ans = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        b[v[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        ans += b[i] < b[i-1];
    }
    cout << ans+1;
    return 0;
}
