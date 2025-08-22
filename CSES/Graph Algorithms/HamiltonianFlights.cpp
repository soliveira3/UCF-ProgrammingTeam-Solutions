#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
 
    vector<vector<int>> adjRev(n);
    int dp[(1 << n)][n];
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
 
    rep (i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        adjRev[--v].push_back(--u);
    }
 
    rep (mask, 2, (1 << n))
    {
        if ((mask & 1) == 0) continue;
        if ( (mask & (1 << (n-1))) && (mask != (1 << n) - 1) ) continue;
 
        rep (i, 0, n)
        {
            if ((mask & (1 << i)) == 0) continue;
 
            for (auto v : adjRev[i])
            {
                dp[mask][i] += dp[mask - (1 << i)][v];
                if (dp[mask][i] > mod) dp[mask][i] -= mod;
            }
        }
    }
 
    cout << dp[(1 << n) - 1][n-1] << '\n';
}