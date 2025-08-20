#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n;
    cin >> n;
    vll a(n);
    rep (i, 0, n) cin >> a[i];
 
    bitset<(int)1e5+1> dp;
    dp[0] = true;
 
    rep (i, 0, n)
        dp |= (dp << a[i]);
 
    vll ans;
    rep (i, 1, 1e5+1)
        if (dp[i]) ans.push_back(i);
 
    cout << sz(ans) << '\n';
    rep (i, 0, sz(ans)) cout << ans[i] << " ";
    cout << '\n';
}