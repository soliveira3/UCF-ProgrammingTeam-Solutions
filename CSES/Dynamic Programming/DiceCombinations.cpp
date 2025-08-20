#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> dp(1000005, -1);
 
 
ll diceRoll(ll n)
{
	if (n == 0) return 1;
	if (n < 0) return 0;
 
	if (dp[n] != -1) return dp[n]; // Test case last
 
 
	dp[n] = 0;
 
	for (ll i = 1; i <= 6; i++)
	{
		dp[n] += diceRoll(n-i);
		dp[n] = dp[n] % (ll)1000000007;
	}
 
	return dp[n];
}
 
void solve()
{
	ll n; cin >> n;
 
	cout << diceRoll(n) << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}