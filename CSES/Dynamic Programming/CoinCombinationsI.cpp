#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dp;
 
int findCoins(ll n, vector<ll> &a)
{
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
 
    dp[n] = 0;
    for (auto x : a)
    {
        dp[n] += findCoins(n-x, a);
        dp[n] %= 1000000007;
    }
 
    return dp[n];
}
 
void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    dp.assign(k+1, -1);
    for (ll i = 0; i < n; i++) cin >> a[i];
 
    cout << findCoins(k, a) << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}