//https://cses.fi/problemset/task/1651
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const int nmax = 2e5;
 
ll v[nmax+5], aint[4*nmax+5], lazy[4*nmax+5];
 
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
 
void update(int nod, int st, int dr, int left, int right, int val) {
    if(lazy[nod] != 0) {
        aint[nod] += 1ll * lazy[nod] * (dr - st + 1);
        if(st != dr) {
            lazy[2 * nod] += lazy[nod];
            lazy[2 * nod + 1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st >= left && dr <= right) {
        lazy[nod] += val;
        return;
    }
    int mid = (st + dr) / 2;
    if(left <= mid) {
        update(2*nod, st, mid, left, right, val);
    }
    if(right > mid) {
        update(2*nod+1, mid+1, dr, left, right, val);
    }
    aint[nod] = aint[2*nod] + aint[2*nod+1] + lazy[2*nod] * (mid - st + 1) + lazy[2*nod+1] * (dr - mid);
}
 
ll query(int nod, int st, int dr, int pos) {
    if(lazy[nod] != 0) {
        aint[nod] += lazy[nod] * (dr - st + 1);
        if (st != dr) {
            lazy[2 * nod] += lazy[nod];
            lazy[2 * nod + 1] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    if(st == dr) {
        return aint[nod];
    }
    int mid = (st + dr) / 2;
    ll rez = 0;
    if(pos <= mid) {
        rez = query(2*nod, st, mid, pos);
    } else {
        rez = query(2*nod+1, mid+1, dr, pos);
    }
    aint[nod] = aint[2*nod] + aint[2*nod+1] + lazy[2*nod] * (mid - st + 1) + lazy[2*nod+1] * (dr - mid);
    return rez;
}
 
int main() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int a, b, val; cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        }
        if(op == 2) {
            int pos; cin >> pos;
            cout << query(1, 1, n, pos) << "\n";
        }
    }
    return 0;
}
