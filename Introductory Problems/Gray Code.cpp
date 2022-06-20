//https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
 
using namespace std;
 
void comp(int n) {
    for(int i = 0; i < (1 << n); i++) {
        bitset<16> b(i^(i>>1));
        string s = b.to_string();
        cout << s.substr(16-n) << "\n";
    }
}
 
int main() {
    int n; cin >> n;
    comp(n);
    return 0;
}
