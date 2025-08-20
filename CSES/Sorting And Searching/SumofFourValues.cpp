#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, x;
    cin >> n >> x;
    vll a(n);
    rep (i, 0, n) cin >> a[i];

    map<ll, pll> mp;
    rep (i, 0, n)
    {
        rep (j, i+1, n)
            if (mp.count(x-a[i]-a[j]))
            {
                pll pr = mp.at(x-a[i]-a[j]);
                cout << pr.first+1 <<  ' ' << pr.second+1 <<  ' ' << i+1 << ' ' << j+1 << '\n';
                return 0;
            }

        rep (j, 0, i) mp[a[i]+a[j]] = {j, i};
    }

    cout << "IMPOSSIBLE\n";
}