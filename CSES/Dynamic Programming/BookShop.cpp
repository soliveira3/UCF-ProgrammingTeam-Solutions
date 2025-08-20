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
 
    ll n, w;
    cin >> n >> w;
    vll price(n+1, 0), value(n+1, 0);
 
    rep(i, 0, n) cin >> price[i];
    rep(i, 0, n) cin >> value[i];
 
    vector<ll> dp1(w+1, 0);
    vector<ll> dp2(w+1, 0);
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp2[j] = dp1[j];
            if (j >= price[i-1]) dp2[j] = max(dp2[j], dp1[j-price[i-1]] + value[i-1]);
        }
        swap(dp1, dp2);
    }
 
    cout << dp1[w] << '\n';
}