#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);


    int r, g, b;
    cin >> r >> g >> b;

    int r1, g1, b1;
    cin >> r1 >> g1 >> b1;

    r = max(0, r-r1);
    g = max(0, g-g1);
    b = max(0, b-b1);

    int rg, gb;
    cin >> rg >> gb;

    if (rg < r){
        cout << "-1\n";
        return 0;
    }

    int total = r;
    rg -= r;

    if (gb < b){
        cout << "-1\n";
        return 0;
    }

    total += b;
    gb -= b;

    if (rg + gb < g) {
        cout << "-1\n";
        return 0;
    }

    total += g;

    cout << total << '\n';
}