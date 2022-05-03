//https://cses.fi/problemset/task/1090
#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 2 * 1e5;
 
int n, x, v[nmax+5], i, j, nr;
bool viz[nmax+5];
 
int main(){
    cin >> n >> x;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    i = 1, j = n;
    while(i < j) {
        if(v[i] + v[j] > x) {
            j--;
        } else {
            nr++;
            viz[i] = true;
            viz[j] = true;
            i++;
            j--;
        }
    }
    for(int k = 1; k <= n; k++) {
        viz[k] = !viz[k];
        nr += viz[k];
    }
    cout << nr;
    return 0;
}
