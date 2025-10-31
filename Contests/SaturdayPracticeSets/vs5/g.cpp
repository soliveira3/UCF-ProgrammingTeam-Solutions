#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s = "!A1@a2#B3$b4";
    sort(s.begin(), s.end());

    int count = 0, ct = 0;
    do {
        if (count++ % 997 == 0 && ct++)
            cout << s << "\n";
    } while (count < n && next_permutation(s.begin(), s.end()));
}