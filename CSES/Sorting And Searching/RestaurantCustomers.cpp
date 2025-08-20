#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
	ll n;
    cin >> n;
    vector<pair<ll, ll>> times;
 
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
 
    sort(times.begin(), times.end());
 
    ll count = 0, maxCount = 0;
    for (int i = 0; i < 2*n; i++)
    {
        count += times[i].second;
        maxCount = max(count, maxCount);
    }
 
    cout << maxCount << '\n';
 
    return 0;
}