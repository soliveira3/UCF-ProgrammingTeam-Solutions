#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
	ll n, x;
    cin >> n >> x;
 
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll y; cin >> y;
        a.push_back({y, i+1});
    }
 
    sort(a.begin(), a.end());
 
    ll p1 = 0, p2 = n-1;
    while (p2 > p1)
    {
        if (a[p1].first + a[p2].first == x)
        {
            cout << a[p1].second << " " << a[p2].second << '\n';
            return 0;
        }
 
        if (a[p1].first + a[p2].first > x) p2--;
        else p1++;
    }
 
    cout << "IMPOSSIBLE\n";
 
	return 0;
}