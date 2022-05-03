//https://cses.fi/problemset/task/1618
#include <bits/stdc++.h>
 
using namespace std;
 
int nz(int n) {
    int nr = 0, nr1 = 0, p1 = 2, p2 = 5;
    if(n == 5) {
        return 1;
    } else {
        while (p1 < n) {
            nr += n / p1;
            p1 *= 2;
        }
        while (p2 < n) {
            nr1 += n / p2;
            p2 *= 5;
        }
        return nr1;
    }
}
 
int main() {
    int n;
    cin >> n;
    cout << nz(n);
    return 0;
}
