#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    ll n; cin >> n;
 
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> diffFor(n, 0);
    vector<ll> diffBack(n, 0);
 
 
    for (int i = 1; i < n; i++)
        diffFor[i] = diffFor[i-1] + ((a[i]-a[i-1])*(i));
 
    for (int i = n-2; i >= 0; i--)
        diffBack[i] = diffBack[i+1] + ((a[i+1]-a[i])*(n-i-1));
 
 
    ll minimum = LLONG_MAX;
    for (int i = 0; i < n; i++)
        minimum = min(minimum, diffBack[i]+diffFor[i]);
 
 
    cout << minimum << '\n';
 
    return 0;
}