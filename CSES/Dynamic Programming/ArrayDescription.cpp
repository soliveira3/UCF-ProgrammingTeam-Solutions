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
 
    ll n, x;
    cin >> n >> x;
    ll mod = 1e9 + 7;
 
    vector<vll> dp(n, vll(x, 0));
    vll a(n);
    rep (i, 0, n)
    {
        cin >> a[i];
        if (a[i]) dp[i][a[i]-1] = 1;
        else rep (j, 0, x) dp[i][j] = 1;
    }
 
    // Doing the DP
    for (int i = n-2; i >= 0; i--)
        rep (j, 0, x)
        {
            if (j == 0) dp[i][j] = (dp[i][j]*dp[i+1][j] + dp[i][j]*dp[i+1][j+1]) % mod;
            else if (j == x-1) dp[i][j] = (dp[i][j]*dp[i+1][j] + dp[i][j]*dp[i+1][j-1]) % mod;
            else dp[i][j] = (dp[i][j]*dp[i+1][j-1] + dp[i][j]*dp[i+1][j] + dp[i][j]*dp[i+1][j+1]) % mod;
        }
 
    ll ans = 0;
    rep (i, 0, x) ans = (ans + dp[0][i]) % mod;
 
    cout << ans << '\n';
}

