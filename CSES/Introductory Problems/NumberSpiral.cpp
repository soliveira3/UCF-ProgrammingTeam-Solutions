#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll q; cin >> q;
 
	ll x, y;
	ll ans = 1;
 
	for (int i = 0; i < q; i++)
	{
		cin >> y >> x;
 
		if (y > x)
		{
			if (y % 2 == 0) ans = (y*y) - (x-1);
			else ans = ((y*y) - (y-1)) - (y-x);
		}
		else
		{
			if (x % 2 == 1) ans = (x*x) - (y-1);
			else ans = ((x*x) - (x-1)) - (x-y);
		}
 
		cout << ans << '\n';
	}
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}