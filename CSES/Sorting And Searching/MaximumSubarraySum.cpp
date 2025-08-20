#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
	ll n;
    cin >> n;
 
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
 
    vector<ll> sum(n, 0);
    sum[0] = max((ll)0, a[0]);
    ll maximum = sum[0];
 
    for (ll i = 1; i < n; i++)
    {
        sum[i] = max((ll)0, sum[i-1] + a[i]);
        maximum = max(maximum, sum[i]);
    }
 
    ll maxE = a[max_element(a.begin(), a.end()) - a.begin()];
 
    if (maxE < 0) cout << maxE;
    else cout << maximum << '\n';
 
 
 
	return 0;
}