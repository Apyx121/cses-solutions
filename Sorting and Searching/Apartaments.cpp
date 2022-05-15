//https://cses.fi/problemset/task/1084/
#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;

int v[nmax+5], a[nmax+5], nr;

int main() {
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(v+1, v+n+1);
    sort(a+1, a+m+1);
    int i = 1, j = 1;
    while(i <= n && j <= m) {
        if(abs(v[i] - a[j]) <= k) {
            i++;
            j++;
            nr++;
        } else {
            if(v[i] - a[j] > k) {
                j++;
            } else {
                i++;
            }
        }
    }
    cout << nr;
    return 0;
}
