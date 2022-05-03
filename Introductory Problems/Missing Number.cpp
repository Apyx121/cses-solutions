//https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long n, s = 0, x, s1 = 0;
    cin >> n;
    for(int i = 1; i <= n - 1; i++) {
        cin >> x;
        s += x;
    }
    for(int i = 1; i <= n; i++) {
        s1 += i;
    }
    cout << s1 - s;
    return 0;
}
