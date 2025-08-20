#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<bool> taken(n+1, false);
 
	ll x;
	for (int i = 0; i < n-1; i++)
	{
		cin >> x;
		taken[x] = true;
	}
 
	for (int i = 1; i <= n; i++)
		if (!taken[i])
		{
			cout << i << '\n';
			break;
		}
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}