#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
 
	int count = 1;
 
	for (int i = 0; i < n; i+=2)
	{
		a[i] = count;
		count++;
	}
 
	for (int i = 1; i < n; i+=2)
	{
		a[i] = count;
		count++;
	}
 
 
	if (n == 1) cout << 1 << '\n';
	else if (n == 4) cout << "2 4 1 3" << '\n';
	else if (n < 5) cout << "NO SOLUTION\n";
	else
	{
		for (auto x : a) cout << x << " ";
		cout << '\n';
	}
}
 
int main ()
{
	ll tc = 1;
	// cin >> tc;
	for (int i = 0; i < tc; i++) solve();
 
	return 0;
}