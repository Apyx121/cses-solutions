//https://cses.fi/problemset/task/1646/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int nmax = 2e5;
 
ll v[nmax+5], aint[4*nmax+5];
 
void build(int nod, int st, int dr) {
    if(st == dr) {
        aint[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(2*nod, st, mid);
    build(2*nod+1, mid+1, dr);
    aint[nod] = aint[2*nod] + aint[2*nod+1];
}
 
ll query(int nod, int st, int dr, int left, int right) {
    if(st >= left && dr <= right) {
        return aint[nod];
    }
    int mid = (st + dr) / 2;
    ll rez = 0;
    if(left <= mid) {
        rez += query(2*nod, st, mid, left, right);
    }
    if(right > mid) {
        rez += query(2*nod+1, mid+1, dr, left, right);
    }
    return rez;
}
 
int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        cout << query(1, 1, n, x, y) << "\n";
    }
    return 0;
}
