//https://cses.fi/problemset/task/1754
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int x, y;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        cin >> y;
        cout << (((x+y) % 3 == 0 && min(x, y) * 2 >= max(x, y)) ? "YES" : "NO") << endl;
    }
    return 0;
}
