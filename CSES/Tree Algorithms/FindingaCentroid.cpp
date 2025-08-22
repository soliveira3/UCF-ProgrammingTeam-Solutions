#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
ll n;
vll subSize;
vector<vll> adj;
 
void dfs(ll u, ll p)
{
    for (auto v : adj[u])
        if (v != p)
        {
            dfs(v, u);
            subSize[u] += subSize[v];
        }
}
 
ll centroid(ll u, ll p)
{
    ll mx = -1;
    for (auto v : adj[u])
        if (v != p) if (mx == -1 || subSize[v] > subSize[mx])
            mx = v;
 
    if (mx == -1 || subSize[mx] <= n/2) return u;
    return centroid(mx, u);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    cin >> n;
    subSize.assign(n, 1);
    adj.assign(n, vll());
 
    rep (i, 0, n-1)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(0, -1);
    cout << centroid(0, -1)+1 << '\n';
}