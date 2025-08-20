#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, x;
    cin >> n >> x;
    vll a(n+1, 0);
    rep (i, 1, n+1)
        cin >> a[i];
 
    ll p1 = 0, p2 = 0;
    ll curSum = 0, ans = 0;
    while (p1 < n+1 && p2 < n+1)
    {
        if (curSum > x && p1 != p2)
        {
            curSum -= a[p1];
            p1++;
            continue;
        }
 
        if (curSum == x) ans++;
 
        p2++;
        if (p2 >= n+1) break;
        curSum += a[p2];
    }
 
    cout << ans << '\n';
 
    return 0;
}