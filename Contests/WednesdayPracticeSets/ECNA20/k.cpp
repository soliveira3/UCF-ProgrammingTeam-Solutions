#include <bits/stdc++.h>
using namespace std;

const int maxn=5e3+5, maxm = 21;
int dp[maxn][maxm];

int solve(int len, int left) {
    if (len == 0) return 0;
    if (left == 0) return 1e9;
    
    int &res = dp[len][left];
    if (res != -1) return res;
    res = 1e9;
    for (int i = 1; i <= len; i++) {
        res = min(res, 1 + max(
            solve(i-1, left-1),
            solve(len-i, left)
        ));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    int lo = 1e9, hi = -1e9;
    int best = solve(n, m);

    for (int i = 1; i <= n; i++) {
        if (max(solve(i-1, m-1), solve(n-i, m)) + 1 == best) {
            lo = min(lo, i);
            hi = max(hi, i);
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     if (dp[n][i] < best) {
    //         best = dp[n][i];
    //         lo = i;
    //         hi = i;
    //     } else if (dp[n][i] == best) {
    //         hi = i;
    //     }
    // }

    cout << best << " ";
    if (lo == hi) cout << lo << "\n";
    else cout << lo << "-" << hi << "\n";
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}


// 1 1
// -1 1 1 
// -1 1 1 
// -1 1 1 
// -1 -1 1 