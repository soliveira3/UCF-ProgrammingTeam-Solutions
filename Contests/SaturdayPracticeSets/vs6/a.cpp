#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == -999) cout << -998 << " " << -1 << '\n';
    else if(n == 1) cout << 2 << " " << -1 << '\n';
    else cout << 1 << " " << n-1 << '\n';
}