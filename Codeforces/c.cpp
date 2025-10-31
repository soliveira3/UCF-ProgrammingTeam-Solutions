#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

void solve()
{
    ll n, X;
    cin >> n >> X;

    vll a(n), ans;
    rep (i, 0, n) cin >> a[i];

    sort(all(a));

    ll p1 = 0, p2 = n-1, S = 0, pts = 0;
    while (p1 <= p2) {
        if (((S + a[p2]) / X) > (S/X)) {
            ans.push_back(a[p2]);
            pts += a[p2];
            S += a[p2];
            p2--;
        }
        else {
            if (((S + a[p1]) / X) > (S/X)) pts += a[p2];
            ans.push_back(a[p1]);
            S += a[p1];
            p1++;
        }
    }

    cout << pts << '\n';
    rep (i, 0, n) cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc; cin >> tc;
    while (tc--) solve();
}