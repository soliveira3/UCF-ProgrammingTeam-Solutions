#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll minX = 1e9, maxX = -1e9;
    ll minY = 1e9, maxY = -1e9;

    while (n--) {
        ll x, y; cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << (maxX - minX + 2) * 2 + (maxY - minY + 2) * 2 << "\n";
}