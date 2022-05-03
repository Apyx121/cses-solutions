//https://cses.fi/problemset/task/1621
#include <bits/stdc++.h>
 
using namespace std;
 
map<int,int> m;
 
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    cout << m.size();
    return 0;
}
