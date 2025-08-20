#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void solve()
{
	ll n, m;
	cin >> n >> m;
	multiset<ll, greater<ll>> a;
 
	ll x;
	for (int i = 0; i < n; i++) { cin >> x; a.insert(x); }
 
 
	ll q;
	for (ll i = 0; i < m; i++)
	{
		cin >> q;
		auto it = a.lower_bound(q);
 
		if (it == a.end())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *it << endl;
            a.erase(it);
        }
	}
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}