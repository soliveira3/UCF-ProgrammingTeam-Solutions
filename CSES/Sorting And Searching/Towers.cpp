#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
	ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
	ll n; cin >> n;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
 
	vector<ll> towers;
 
	for (int i = 0; i < n; i++)
	{
		auto bound = upper_bound(towers.begin(), towers.end(), a[i]);
 
		if (bound == towers.end())
        {
			towers.push_back(a[i]);
            continue;
        }
 
        auto index = bound;
        towers.erase(index);
 
        auto newIndex = lower_bound(towers.begin(), towers.end(), a[i]);
        towers.insert(newIndex, a[i]);
	}
 
 
	cout << towers.size() << '\n';
	return 0;
}