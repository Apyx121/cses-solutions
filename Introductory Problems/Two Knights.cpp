//https://cses.fi/problemset/task/1072
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    int n; cin >> n;
    for(ll i = 1; i <= n; i++) {
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << "\n";
    }
    return 0;
}
