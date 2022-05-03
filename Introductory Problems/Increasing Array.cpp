//https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long s = 0;
    int cop = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x < cop) {
            s += (cop - x);
            x = cop;
        }
        cop = x;
    }
    cout << s;
    return 0;
}
