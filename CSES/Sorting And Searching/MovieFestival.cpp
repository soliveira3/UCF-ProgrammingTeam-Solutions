#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<pair<ll, ll>> movies(n);
 
	ll u, v;
	for (ll i = 0; i < n; i++)
	{
		cin >> u >> v;
		movies[i] = make_pair(v, u);
	}
 
	sort(movies.begin(), movies.end());
 
	ll moviesWatched = 1;
	for (int i = 0; i < n; i++)
	{
		ll j = i+1;
		while (j < n && movies[i].first > movies[j].second) j++;
 
		if (j == n) break;
 
		i = j-1;
		moviesWatched++;
	}
 
	cout << moviesWatched << '\n';
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}