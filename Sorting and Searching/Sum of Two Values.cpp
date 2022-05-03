//https://cses.fi/problemset/task/1640
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<pair<int,int>> v;
 
int main() {
    ll n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        ll a; cin >> a;
        v.emplace_back(a, i);
    }
    sort(v.begin(), v.end());
    ll i = 0, j = n-1;
    while(i < j) {
        if(v[i].first + v[j].first > x) {
            j--;
        } else if(v[i].first + v[j].first < x) {
            i++;
        } else if(v[i].first + v[j].first == x) {
            cout << v[j].second << " " << v[i].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
