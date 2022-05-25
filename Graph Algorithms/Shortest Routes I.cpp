//https://cses.fi/problemset/task/1671/
#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1e5;
 
vector<pair<long long,long long>> v[nmax+5];
priority_queue<pair<long long,long long>> pq;
long long ans[nmax+5];
 
int main() {
    long long n, q; cin >> n >> q;
    for(int i = 1; i <= q; i++) {
        long long x, y, c; cin >> x >> y >> c;
        v[x].emplace_back(c, y);
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = LONG_LONG_MAX;
    }
    pq.push({0, 1});
    ans[1] = 0;
    while(!pq.empty()) {
        pair<long long,long long> now = pq.top();
        pq.pop();
        if(ans[now.second] < -now.first) {
            continue;
        }
        for(auto x : v[now.second]) {
            if(-now.first + x.first < ans[x.second]) {
                ans[x.second] = -now.first + x.first;
                pq.push({-(-now.first+x.first), x.second});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
