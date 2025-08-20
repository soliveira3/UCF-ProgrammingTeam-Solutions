#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, x, ans = 0, z = 0;
    cin >> n >> x;
    vll a(n/2), b(n - (n/2)), first;
    rep (i, 0, n/2) cin >> a[i];
    rep (i, 0, n - (n/2)) cin >> b[i];

    rep (mask, 0, (1 << sz(a)))
    {
        z = 0;
        rep (i, 0, sz(a))
            if (mask & (1 << i))
                z += a[i];

        first.push_back(z);
    }

    sort(all(first));

    rep (mask, 0, (1 << sz(b)))
    {
        z = 0;
        rep (i, 0, sz(b))
            if (mask & (1 << i))
                z += b[i];

        ans += upper_bound(all(first), x-z) - lower_bound(all(first), x-z);
    }

    cout << ans << '\n';
}