#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void split(ll n)
{
	ll sum = ((n)*(n+1)) / 4;
 
	ll index = n;
	set<ll> st;
	while (sum > 0)
	{
		if (sum - index < 0)
		{
			st.emplace(sum);
			sum = 0;
		}
 
		else
		{
			st.emplace(index);
			sum -= index;
		}
 
		index--;
	}
 
	vector<ll> v1;
	vector<ll> v2;
	sum = ((n)*(n+1)) / 2;
	ll s2 = 0;
	bool possible = (sum % 2 == 0);
 
	for (int i = 1; i <= n; i++)
	{
		if (st.find(i) != st.end()) v1.push_back(i);
		else
		{
			v2.push_back(i);
			s2 += i;
		}
	}
 
	if (possible)
	{
		cout << "YES\n";
		cout << v1.size() << '\n';
		for (auto x : v1) cout << x << ' ';
		cout << '\n';
 
		cout << v2.size() << '\n';
		for (auto x : v2) cout << x << ' ';
		cout << '\n';
	}
 
	else cout << "NO\n";
}
 
void solve()
{
	ll n; cin >> n;
 
	split(n);
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}