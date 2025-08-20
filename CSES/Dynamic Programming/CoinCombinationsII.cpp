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
    vll a(n), dp(x+1, 0);
    dp[0] = 1;
 
    rep (i, 0, n) cin >> a[i];
 
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= x; j++)
            if (dp[j - a[i]]) dp[j] = (dp[j-a[i]] + dp[j]) % (ll)(1e9 + 7);
 
    cout << dp[x] << '\n';
}