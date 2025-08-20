#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main ()
{
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
 
    vll dp;
    for (auto x : a)
    {
        ll index = lower_bound(begin(dp), end(dp), x) - begin(dp);
 
        if (index == sz(dp)) dp.push_back(x);
        else dp[index] = x;
    }
 
    cout << sz(dp) << '\n';
 
    return 0;
}

