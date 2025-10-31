#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b,c;
    cin >> a >> b >> c;
    if((b-a) % c == 0) cout << "S\n";
    else cout << "N\n";
    return 0;
}