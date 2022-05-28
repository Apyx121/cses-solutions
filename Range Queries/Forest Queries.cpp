//https://cses.fi/problemset/task/1652/
#include <bits/stdc++.h>
#define nmax 1000
#define lsb(x) (x&(-x))
 
using namespace std;
 
char mat[nmax+5][nmax+5];
int fen[nmax+5][nmax+5];
int n, m;
 
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
 
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == '*') {
                update(i, j, 1);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
        cout << query(x1, y1) - query(x1, y-1) - query(x-1, y1) + query(x-1, y-1) << "\n";
    }
    return 0;
}
