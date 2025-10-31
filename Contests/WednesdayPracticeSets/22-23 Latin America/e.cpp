#include <bits/stdc++.h>
using namespace std;


#define rep(i, a, b) for (int i = a; i < b; ++i)

// int solve(int a, int b, int c) {
//     int n = a + b + c;
//     vector<int> taken(n+1);
//     taken[b] = 1;

//     int ans = 0;
//     if (a != 0) {
//         for ()
//     }
// }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, e1; cin >> n >> k >> e1;
    int e2 = n - k - e1;
    
    // cout << min(solve(e1, k, e2), solve(e2, k, e1)) << "\n";

    if (e1 > e2) swap(e1, e2);

    if (e1 > 20) {
        cout << "0\n";
        return 0;
    }

    int best = n;
    rep(a, 0, e1 + 1) {
        if (a == k) continue;
        rep(b, 0, e1 - a + 1) {
            if (b == k || (b == a && b != 0)) continue;
            if (e2 > 20) {
                best = min(best, e1 - a - b);
            }
            rep(c, 0, e2 + 1) {
                if (c == k || (c != 0 && (c == a || c == b))) continue;
                rep (d, 0, e2 - c + 1) {
                    if (d == k || (d != 0 && (d == a || d == b || d == c))) continue;

                    best = min(best, e1 - a - b + e2 - c - d);
                }
            }
        }
    }

    cout << best << "\n";



}