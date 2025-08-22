#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
vll distinct, a, nodeSize;
vector<vll> adj;
vector<set<ll>> colors;
 
void dfs(ll u, ll p)
{
    ll big = -1;
    for (ll v : adj[u])
    {
        if (v == p) continue;
        dfs(v, u);
        if (big == -1 || nodeSize[v] > nodeSize[big]) big = v;
        nodeSize[u] += nodeSize[v];
    }
 
    // Big Child
    if (big != -1) swap(colors[u], colors[big]);
 
    // Smaller childred
    for (ll v : adj[u])
        if (v != big && v != p)
            colors[u].insert(all(colors[v]));
 
    colors[u].insert(a[u]);
    distinct[u] = sz(colors[u]);
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n;
    cin >> n;
    a.assign(n, 0);
    nodeSize.assign(n, 1);
    distinct.assign(n, 0);
    colors.assign(n, set<ll>());
    rep (i, 0, n) cin >> a[i];
 
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
 
    rep (i, 0, n) cout << distinct[i] << ' ';
    cout << '\n';
}