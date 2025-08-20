#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main ()
{
	ll n, x;
    cin >> n >> x;
 
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
 
    sort(a.begin(), a.end());
 
    ll p1 = 0, p2 = n-1;
    ll count = 0;
 
    while (p2 >= p1)
    {
        count++;
        if (p2 == p1) break;
        if (a[p1] + a[p2] <= x) p1++;
        p2--;
    }
 
    cout << count << '\n';
 
    return 0;
}