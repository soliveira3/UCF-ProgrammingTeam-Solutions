#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
 
	ll x = 5;
	ll numZeros = 0;
	while (x <= n)
	{
		numZeros += (n/x);
		x*=5;
	}
 
	cout << numZeros << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}