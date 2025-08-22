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
 
    ll n, q, m = 30;
    cin >> n >> q;
 
    vector<vector<int>> jmp(n, vector<int>(m));
 
    // Setting the one jump distances
    rep (i, 0, n)
    {
        int x; cin >> x; x--;
        jmp[i][0] = x;
    }
 
    rep (j, 1, m)
        rep (i, 0, n)
            jmp[i][j] = jmp[jmp[i][j-1]][j-1];
 
    while (q--)
    {
        ll x, k;
        cin >> x >> k; x--;
 
        for (int pow = m; pow >= 0LL; pow--)
            if (k >= (1LL << pow))
            {
                x = jmp[x][pow];
                k -= (1LL << pow);
            }
 
        cout << x+1 << '\n';
    }
}

