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
    ll R, X, D, n;
    cin >> R >> X >> D >> n;
    string s;
    cin >> s;

    ll ct = 0;
    rep (i, 0, n) {
        if (s[i] == '1') ct++;
        else if (s[i] == '2' && R < X) ct++;

        if (s[i] == '1' || (s[i] == '2' && R < X))
            R = max(0LL, R-D);
    }

    cout << ct << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc; cin >> tc;
    while (tc--) solve();
}