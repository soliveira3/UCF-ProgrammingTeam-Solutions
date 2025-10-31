#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, g;
    cin >> n >> g;

    vll pref(n, 0);
    pref.assign(n, 0);
    rep (i, 0, n) {
        cin >> pref[i];
        if (i) pref[i] += pref[i-1];
    }

    vll dp(n, 0), prev(n, 0);
    ll mx = 0, prevMx = 0;
    ll ct = 0, start = 0;

    rep (size, 1, n+1)
    {
        rep (i, start, (n-size+1))
        {
            ct++;
            ll sub = i ? pref[i-1] : 0;
            ll score = g - (pref[i + size - 1] - sub);

            if (i == 0)
                dp[i] = max(0LL, max(score, prev[i]));
            
            else
                dp[i] = max(max(score + prev[i-1], prev[i-1]), max(dp[i-1], 0LL));

            mx = max(mx, dp[i]);            
        }


        if (mx == prevMx) {
            // cout << "h\n";
            break;
        }

        start += size;
        prevMx = mx;
        swap(dp, prev);
    }

    cout << mx << '\n';
}//////.