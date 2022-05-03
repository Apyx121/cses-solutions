//https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string s;
    long long nr = 1, mx = 0;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        nr = 1;
        while(s[i] == s[i+1]) {
            nr++;
            i++;
        }
        mx = max(nr, mx);
    }
    cout << mx;
    return 0;
}
