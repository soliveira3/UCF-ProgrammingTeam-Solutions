#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vector<vll> adj;
vll par;
vll depth;
 
void dfs(ll u, ll p, ll d)
{
    depth[u] = d;
    for (auto v : adj[u])
    {
        if (v != p) dfs(v, u, d+1);
        par[v] = u;
    }
}
 
vector<vll> treeJump(vll& P)
{
    ll on = 1, d = 1;
    while (on < (int)P.size()) on *=2, d++;
 
    vector<vll> jmp(d, P);
    rep(i, 1, d) rep(j, 0, P.size())
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
 
    return jmp;
}
 
ll jmp (vector<vll> &tbl, ll node, ll steps)
{
    rep(i, 0, tbl.size())
        if (steps & (1 << i)) node = tbl[i][node];
 
    return node;
}
 
ll lca(vector<vll> &tbl, vll &depth, ll a, ll b)
{
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
 
    for (int i = tbl.size(); i--;)
    {
        ll c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
 
    return tbl[0][a];
}
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
 
    adj.assign(n, vll());
    par.assign(n, 0);
    depth.assign(n, 0);
 
    rep (i, 0, n-1)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(0, -1, 0);
    vector<vll> tbl = treeJump(par);
 
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--; b--;
 
        ll c = lca(tbl, depth, a, b);
        ll dis = depth[a] + depth[b] - 2*depth[c];
        cout << dis << '\n';
    }
}