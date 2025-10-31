#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n,vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            g[i][j] = (c == 'G');
        }
    }

    // [flipped (0 -> y,  1 -> n)][r][c]
    vector<vector<vector<int>>> dp(2, vector<vector<int>> (n+1, vector<int>(m+1, 0)));
    int res = 1;
    dp[0][0][0] = g[0][0];
    dp[1][0][0] = !g[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!i && !j)continue;
            if(!i || !j) {
                dp[0][i][j] = g[i][j];
                dp[1][i][j] = !g[i][j];
                res = max({res,dp[0][i][j], dp[1][i][j]});
                continue;
            }
            for(int k = 0; k < 2; k++) {
                if(k && g[i][j]) continue;
                if(!k && !g[i][j]) continue;
                int d0 = dp[0][i-1][j-1];
                int d1 = dp[1][i-1][j-1];
                int p0 = dp[0][i-1][j];
                int p1 = dp[1][i-1][j];
                int prev = dp[k][i][j-1];

                dp[k][i][j] = max({
                    min({p0,d0,prev}),
                    min({p1,d1,prev})
                });

                // cout << "AT " << i << " " << j << " " << k << " " << dp[k][i][j] << '\n';

                if(dp[k][i][j]) dp[k][i][j] += 1;

                dp[k][i][j] = max(dp[k][i][j], 1);

                res = max(res, dp[k][i][j]);
            }
        }
    }

    // for(int i = 0; i < n; i++) { 
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[0][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << '\n';

    // for(int i = 0; i < n; i++) { 
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[1][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << (res * res) << '\n';
}