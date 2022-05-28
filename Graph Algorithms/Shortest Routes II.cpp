//https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
#define nmax 500
 
using namespace std;
 
const long long inf = 1e18;
 
long long dist[nmax+5][nmax+5];
 
int main() {
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = inf;
            dist[j][i] = inf;
        }
    }
    for(int i = 1; i <= m; i++) {
        int x, y, c; cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], 1LL*c);
        dist[y][x] = min(dist[y][x], 1LL*c);
    }
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(1LL*dist[i][j], 1LL * dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 1; i <= q; i++) {
        int a, b; cin >> a >> b;
        if(dist[a][b] == inf) {
            cout << -1 << "\n";
        } else {
            cout << dist[a][b] << "\n";
        }
    }
    return 0;
}
