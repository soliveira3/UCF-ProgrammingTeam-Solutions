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
 
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    rep (i, 0, n) cin >> a[i];
    rep (i, 0, m) cin >> b[i];
 
    vector<vll> dp(n+1, vll(m+1, 0));
 
    rep (i, 1, n+1)
        rep (j, 1, m+1)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
 
 
    vll ans;
    ll i = n, j = m;
    while (i != 0 && j != 0)
    {
        if (dp[i][j] == dp[i-1][j]) i--;
        else if (dp[i][j] == dp[i][j-1]) j--;
        else
        {
            ans.push_back(b[j-1]);
            i--; j--;
        }
    }
 
    cout << dp[n][m] << '\n';
    reverse(all(ans));
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}