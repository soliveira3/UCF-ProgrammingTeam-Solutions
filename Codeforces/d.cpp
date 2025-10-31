#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

void print(vll &x) {
    rep (i, 0, sz(x)) cout << x[i] << ' ';
    cout << '\n';
}

void solve()
{
    ll n;
    cin >> n;

    vll a(n), sorted;
    rep (i, 0, n) cin >> a[i];

    sorted = a;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());

    vector<bool> isCounting(n+5, false);

    // going backwards - start counting for the guy-1
    vll countDeleteBelow(n+5, 0);
    for (ll i = n-1; i >= 0; i--) {
        if (isCounting[a[i]]) countDeleteBelow[a[i]]++;
        isCounting[a[i]-1] = true;
    }

    // going forwards - start counting for the guy+1
    isCounting.assign(n+5, false);
    vll countDeleteAbove(n+5, 0);
    rep (i, 0, n) {
        if (isCounting[a[i]]) countDeleteAbove[a[i]]++;
        isCounting[a[i]+1] = true;
    }


    /*
        doing the dp on sorted
    */

    ll ans = 0;
    vll dp(sz(sorted), 0);

    rep (i, 0, sz(sorted)) {

        dp[i] = (i-1 >= 0 ? countDeleteBelow[sorted[i-1]] : 0) +
                ((i-2 >= 0 && sorted[i-2] == sorted[i]-2) ? dp[i-2] : 0);


        // at least 4 here and we're trying to skip 2
        ll skipping2 = 1e18;
        if (i-3 >= 0 && sorted[i-3] == sorted[i]-3) {
            skipping2 = countDeleteBelow[sorted[i-1]] + // pos 3
                        countDeleteBelow[sorted[i-2]] + // pos 2
                        dp[i-3];
        }


        dp[i] = min(dp[i], skipping2);


        // last number or end of consecutive range
        if (i == (sz(sorted)-1) || sorted[i+1] != sorted[i]+1) {

            bool atLeast2 = (i-1 >= 0 && sorted[i-1] == sorted[i]-1);
            ll last = dp[i];
            ll secondLast = (atLeast2 ? dp[i-1] : 1e18);

            // adding the last guy
            if (atLeast2) {
                secondLast += countDeleteAbove[sorted[i]];
                dp[i-1] += countDeleteAbove[sorted[i]];
            }

            ans += min(last, secondLast);
        }

    }

    cout << '\n';
    print(sorted);
    print(dp);
    cout << '\n';

    cout << ans << '\n';
}



int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll tc; cin >> tc;
    while (tc--) solve();
}