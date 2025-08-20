#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
void solve()
{
	ll n; cin >> n;
	set<ll> st;
	ll x;
	for (ll i = 0; i < n; i++)
	{
		cin >> x;
		st.emplace(x);
	}
 
	cout << st.size() << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}