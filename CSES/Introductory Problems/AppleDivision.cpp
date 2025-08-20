#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n;
    cin >> n;
 
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
 
    ll minimum = LONG_LONG_MAX;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < n; i++)
        {
            if (mask & (1 << i)) s1 += a[i];
            else s2 += a[i];
        }
        minimum = min(abs(s1-s2), minimum);
    }
 
    cout << minimum << '\n';
 
	return 0;
}