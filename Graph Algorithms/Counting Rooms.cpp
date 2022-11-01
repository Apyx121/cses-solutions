//https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>
 
using namespace std;
 
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
 
const int nmax = 1e3;
 
char mat[nmax+5][nmax+5];
bool viz[nmax+5][nmax+5];
int n, m, nr;
 
bool verif(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}
 
void dfs(int x, int y) {
    viz[x][y] = true;
    for(int k = 0; k < 4; k++) {
        if(verif(x, y)) {
            if(!viz[x+dx[k]][y+dy[k]]) {
                dfs(x+dx[k], y+dy[k]);
            }
        }
    }
}
 
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == '#') {
                viz[i][j] = true;;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(!viz[i][j]) {
                dfs(i, j);
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}
