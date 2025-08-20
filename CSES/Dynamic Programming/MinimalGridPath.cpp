#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n; cin >> n;
    vector<string> a(n);
    rep (i, 0, n) cin >> a[i];
    string ans(n*2-1, 'Z'+1);
    vector<vector<bool>> valid(n, vector<bool>(n, false));
    valid[0][0] = true;
 
    rep (steps, 0, 2*n-1)
    {
        // Looking at all of the letters at a current step
        for (int i = max(0LL, steps-(n-1)); i <= min(n-1, steps); i++)
        {
            int j = steps - i;
            if (!valid[i][j]) continue;
            ans[steps] = min(ans[steps], a[i][j]);
        }
 
        // Setting the valid/invalid steps
        for (int i = max(0LL, steps-(n-1)); i <= min(n-1, steps); i++)
        {
            int j = steps - i;
            if (i == n-1 && j == n-1) break;
 
            if (valid[i][j] && a[i][j] == ans[steps])
            {
                if (i == n-1) { valid[i][j+1] = true; continue; }
                if (j == n-1) { valid[i+1][j] = true; continue; }
 
                if (a[i+1][j] <= a[i][j+1]) valid[i+1][j] = true;
                if (a[i][j+1] <= a[i+1][j]) valid[i][j+1] = true;
            }
        }
    }
 
    cout << ans << '\n';
}