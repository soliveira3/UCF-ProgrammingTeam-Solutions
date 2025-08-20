#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
ll dp[2][5005][5005];
 
ll solve(ll l, ll r, bool isOne, vll &arr)
{
    if (l+1 == r) return (isOne ? arr[l] : 0LL);
    if (dp[isOne][l][r] != LLONG_MIN) return dp[isOne][l][r];
 
    ll a = solve(l+1, r, !isOne, arr);
    ll b = solve(l, r-1, !isOne, arr);
 
    if (isOne) return dp[isOne][l][r] = max(a + arr[l], b + arr[r-1]);
    else return dp[isOne][l][r] = min(a, b);
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    rep (i, 0, 2) rep (j, 0, 5005) rep (k, 0, 5005)
        dp[i][j][k] = LLONG_MIN;
 
    ll n; cin >> n;
    vll a(n);
    rep (i, 0, n) cin >> a[i];
 
    cout << solve(0, n, true, a) << '\n';
}