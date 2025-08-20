#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
 
ll n;
 
ll search(vector<string> &grid, vector<vector<ll>> &dp, int x, int y)
{
    if (x > n-1 || y > n-1) return 0;
    if (grid[x][y] == '*') return 0;
    if (x == n-1 && y == n-1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
 
    dp[x][y] = search(grid, dp, x+1, y) + search(grid, dp, x, y+1);
    dp[x][y] %= MOD;
 
    return dp[x][y];
}
 
void solve()
{
	cin >> n;
    vector<string> grid(n);
    vector<vector<ll>> dp(n, vector<ll> (n, -1));
 
    for (int i = 0; i < n; i++) cin >> grid[i];
 
    search(grid, dp, 0, 0);
 
    if (n == 1)
    {
        if (grid[0][0] == '.') cout << 1 << '\n';
        else cout << 0 << '\n';
    }
 
    else
    cout << max((ll)0, dp[0][0]) << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}