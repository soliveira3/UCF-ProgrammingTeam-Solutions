#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
 
	ll x = 1;
	for (int i = 0; i < n; i++)
	{
		x += x;
		x %= 1000000007;
	}
 
	cout << x << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}