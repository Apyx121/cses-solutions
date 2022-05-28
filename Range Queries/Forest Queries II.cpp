//https://cses.fi/problemset/task/1739/
#include <bits/stdc++.h>
#define lsb(x) (x&(-x))
#define nmax 1000

using namespace std;

char mat[nmax+5][nmax+5];
int fen[nmax+5][nmax+5];
int n;

int query(int x, int y) {
    int rez = 0;
    while(x >= 1) {
        int cy = y;
        while(cy >= 1) {
            rez += fen[x][cy];
            cy -= lsb(cy);
        }
        x -= lsb(x);
    }
    return rez;
}

void update(int x, int y, int val) {
    while(x <= n) {
        int cy = y;
        while(cy <= n) {
            fen[x][cy] += val;
            cy += lsb(cy);
        }
        x += lsb(x);
    }
}

void changestate(int x, int y) {
    while(x <= n) {
        int cy = y;
        while(cy <= n) {
            fen[x][cy] -= 1;
            cy += lsb(cy);
        }
        x += lsb(x);
    }
}

int main() {
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == '*') {
                update(i, j, 1);
            }
        }
    }
    for(int i = 1; i <= q; i++) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            if(mat[a][b] == '.') {
                mat[a][b] = '#';
                update(a, b, 1);
            } else {
                mat[a][b] = '.';
                changestate(a, b);
            }
        }
        if(op == 2) {
            int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
            cout << query(x1, y1) - query(x1, y-1) - query(x-1, y1) + query(x-1, y-1) << "\n";
        }
    }
    return 0;
}
