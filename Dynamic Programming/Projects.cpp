//https://cses.fi/problemset/task/1140
#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x&(-x))
 
using namespace std;
 
const int nmax = 2e5;
 
struct proiecte {
    int st, dr;
    ll cost;
}v[nmax+5];
 
bool comp(proiecte a, proiecte b) {
    return a.dr < b.dr;
}
 
int mx = 0;
ll aib[2*nmax+5], dp[2*nmax+5];
 
void update(int pos, ll val) {
    while(pos <= mx) {
        aib[pos] = max(aib[pos], val);
        pos += lsb(pos);
    }
}
 
ll query(int pos) {
    ll rez = 0;
    while(pos >= 1) {
        rez = max(rez, aib[pos]);
        pos -= lsb(pos);
    }
    return rez;
}
 
int main() {
    int n; cin >> n;
    vector<ll> a;
    for(int i = 1; i <= n; i++) {
        cin >> v[i].st >> v[i].dr >> v[i].cost;
        a.emplace_back(v[i].st);
        a.emplace_back(v[i].dr);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(v+1, v+n+1, comp);
    for(int i = 1; i <= n; i++) {
        v[i].st = lower_bound(a.begin(), a.end(), v[i].st) - a.begin() + 1;
        v[i].dr = lower_bound(a.begin(), a.end(), v[i].dr) - a.begin() + 1;
        mx = max(v[i].dr, mx);
    }
    for(int i = 1; i <= n; i++) {
        dp[v[i].dr] = max(dp[v[i].dr], query(v[i].st-1) + v[i].cost);
        update(v[i].dr, dp[v[i].dr]);
    }
    ll rez = 0;
    for(int i = 0; i <= mx; i++) {
        rez = max(rez, dp[i]);
    }
    cout << rez;
    return 0;
}
