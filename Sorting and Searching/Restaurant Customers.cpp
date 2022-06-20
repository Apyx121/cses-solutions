//https://cses.fi/problemset/task/1619/
#include <bits/stdc++.h>

using namespace std;

const int nmax = 2e5;

struct events {
    int t, tip;
}v[2*nmax+5];

bool comp(events a, events b) {
    return a.t < b.t;
}

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        v[2*i-1].t = a;
        v[2*i-1].tip = 1;
        v[2*i].t = b;
        v[2*i].tip = -1;
    }
    sort(v+1, v+2*n+1, comp);
    int mx = INT_MIN;
    int s = 0;
    for(int i = 1; i <= 2*n; i++) {
        s += v[i].tip;
        mx = max(mx, s);
    }
    cout << mx;
    return 0;
}
