#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<ll>> dp;
 
ll cut (ll n, ll m)
{
    if (n == m) return 0;
    if (dp[n][m] != LONG_LONG_MAX) return dp[n][m];
 
    for (int i = 1; i < n/2 + 1; i++)
        dp[n][m] = min(dp[n][m], 1 + cut(n-i, m) + cut(i, m));
 
    for (int i = 1; i < m/2 + 1; i++)
        dp[n][m] = min(dp[n][m], 1 + cut(n, m-i) + cut(n, i));
 
    return dp[n][m];
}
 
int main ()
{
    ll n, m;
    cin >> n >> m;
    dp.assign(505, vector<ll> (505, LONG_LONG_MAX));
 
    cout << cut(n, m) << '\n';
	return 0;
}