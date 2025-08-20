#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
 
	for (int i = 0 ; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
 
	ll sum = 1;
	for (int i = 0; i < n; i++)
	{
		if (sum < a[i]) break;
		sum += a[i];
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