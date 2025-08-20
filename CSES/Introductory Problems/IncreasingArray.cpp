#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
 
	ll sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
 
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i-1])
		{
			sum += a[i-1] - a[i];
			a[i] += a[i-1] - a[i];
		}
	}
 
	cout << sum << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}