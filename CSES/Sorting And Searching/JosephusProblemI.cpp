#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	queue<ll> q;
	for (int i = 0; i < n; i++) q.push(i+1);
 
	bool remove = false;
	while (!q.empty())
	{
		ll x = q.front();
		q.pop();
		if (remove) cout << x << " ";
		else q.push(x);
 
		remove = !remove;
	}
 
	cout << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}