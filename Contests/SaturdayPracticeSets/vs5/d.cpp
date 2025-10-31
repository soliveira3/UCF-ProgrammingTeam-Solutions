#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int minX = 1e9+5, maxX = 0;
    int minY = 1e9+5, maxY = 0;

    while (n--) {
        int x, y; cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    cout << "4\n";
    cout << minX << " " << minY << "\n";
    cout << maxX << " " << minY << "\n";
    cout << maxX << " " << maxY << "\n";
    cout << minX << " " << maxY << "\n";
}