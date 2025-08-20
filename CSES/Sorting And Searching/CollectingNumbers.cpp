#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	vector<ll> indexOf(n+1, -1);
	for (ll i = 0; i < n; i++) { cin >> a[i]; indexOf[a[i]] = i; }
 
	ll count = 1;
 
	for (int i = 2; i <= n; i++)
		if (indexOf[i] < indexOf[i-1]) count++;
 
	cout << count << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}