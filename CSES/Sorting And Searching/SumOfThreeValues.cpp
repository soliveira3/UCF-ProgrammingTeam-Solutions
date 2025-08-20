#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
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
    vector<pll> b(n);
    rep (i, 0, n)
    {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i+1;
    }
 
    sort(begin(a), end(a));
    sort(begin(b), end(b));
 
    rep (i, 0, n)
        rep (j, i+1, n)
        {
            ll cur = a[i] + a[j];
            ll idx = lower_bound(a.begin(), a.end(), x - cur) - a.begin();
 
            if (idx == i) idx++;
            if (idx == j) idx++;
 
            if (a[idx] == x - cur)
            {
                cout << b[i].second << " " << b[j].second << " " << b[idx].second << '\n';
                return 0;
            }
        }
 
    cout << "IMPOSSIBLE\n";
 
    return 0;
}