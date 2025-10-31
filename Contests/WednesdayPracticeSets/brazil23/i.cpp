#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int good = 1, x;

    for (int i = 0; i < 8; i++) {
        cin >> x;
        if (x == 9) good = 0;
    }

    cout << (good == 1 ? "S\n" : "F\n");
}