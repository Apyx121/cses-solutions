//https://cses.fi/problemset/task/1735
#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 2e5;
 
int v[nmax+5];
long long aint[4*nmax+5];
pair<long long, int> lazy[4*nmax+5];
 
void propagation(int nod, int st, int dr) {
    if(lazy[nod] == make_pair(0LL, 1)) {
        return;
    }
    if(nod == 6) {
        cout << "";
    }
    if(lazy[nod].second == 1) {
        aint[nod] += lazy[nod].first * (dr - st + 1);
        if(st != dr) {
            if(lazy[2*nod].second == 1) {
                lazy[2*nod].first += lazy[nod].first;
            } else {
                lazy[2*nod].first += lazy[nod].first;
            }
            if(lazy[2*nod+1].second == 1) {
                lazy[2*nod+1].first += lazy[nod].first;
            } else {
                lazy[2*nod+1].first += lazy[nod].first;
            }
        }
    } else {
        aint[nod] = lazy[nod].first * (dr - st + 1);
        if(st != dr) {
            if(lazy[2*nod].second == 1) {
                lazy[2*nod].first = lazy[nod].first;
                lazy[2*nod].second = 2;
            } else {
                lazy[2*nod].first = lazy[nod].first;
            }
            if(lazy[2*nod+1].second == 1) {
                lazy[2*nod+1].first = lazy[nod].first;
                lazy[2*nod+1].second = 2;
            } else {
                lazy[2*nod+1].first = lazy[nod].first;
            }
        }
    }
    lazy[nod] = make_pair(0, 1);
}
 
void build(int nod, int st, int dr) {
    lazy[nod] = make_pair(0, 1);
    if(st == dr) {
        aint[nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(2*nod, st, mid);
    build(2*nod+1, mid+1, dr);
    aint[nod] = aint[2*nod] + aint[2*nod+1];
}
 
void update(int nod, int st, int dr, int left, int right, int val, int op) {
    propagation(nod, st, dr);
    if(st >= left && dr <= right) {
        lazy[nod].first = val;
        lazy[nod].second = op;
        return;
    }
    int mid = (st + dr) / 2;
    if(left <= mid) {
        update(2*nod, st, mid, left, right, val, op);
    }
    if(right > mid) {
        update(2*nod+1, mid+1, dr, left, right, val, op);
    }
    propagation(2*nod, st, mid);
    propagation(2*nod+1, mid+1, dr);
    aint[nod] = aint[2*nod] + aint[2*nod+1];
}
 
long long query(int nod, int st, int dr, int left, int right) {
    propagation(nod, st, dr);
    if(st >= left && dr <= right) {
        return aint[nod];
    }
    int mid = (st + dr) / 2;
    long long rez = 0;
    if(left <= mid) {
        rez += query(2*nod, st, mid, left, right);
    }
    if(right > mid) {
        rez += query(2*nod+1, mid+1, dr, left, right);
    }
    propagation(2*nod, st, mid);
    propagation(2*nod+1, mid+1, dr);
    aint[nod] = aint[2*nod] + aint[2*nod+1];
    return rez;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1, 1, n);
    for(int i = 1; i <= q; i++) {
        int op; cin >> op;
        if(op == 1 || op == 2) {
            int a, b, x; cin >> a >> b >> x;
            update(1, 1, n, a, b, x, op);
        }
        if(op == 3) {
            int a, b; cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
    return 0;
}
