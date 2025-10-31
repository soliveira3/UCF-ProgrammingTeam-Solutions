#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    if (t <= 360) cout << "0\n";
    else if (t <= 390) cout << t - 360 << "\n";
    else if (t <= 570) cout << "30\n";
    else if (t <= 585) cout << t - 570 + 30 << "\n";
    else if (t <= 645) cout << "45\n";
    else cout << t - 645 + 45 << "\n";
}