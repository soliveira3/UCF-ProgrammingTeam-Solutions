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
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, x;
    cin >> n >> x;
 
    vll a(n);
    rep(i, 0, n) cin >> a[i];
 
    ll lo = -1, hi = 2000000000000000000;
    ll ans = -1;
 
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;
        ll taskCompleted = 0;
 
        for (int i = 0; i < n; i++)
        {
            taskCompleted += (mid / a[i]);
            if (taskCompleted >= x) break;
        }
 
        if (taskCompleted >= x)
        {
            ans = mid;
            hi = mid;
        }
 
        else lo = mid;
    }
 
    cout << ans << '\n';
 
    return 0;
}