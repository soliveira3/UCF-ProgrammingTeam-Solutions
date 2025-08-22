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
 
 
 
int main ()
{
    ll n, q;
    cin >> n >> q;
 
    adj.assign(n, vll());
    par.assign(n, 0);
    depth.assign(n, 0);
 
    rep (i, 1, n)
    {
        ll x; cin >> x; x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
 
    dfs(0, -1, 0);
    vector<vll> tbl = treeJump(par);
 
    while (q--)
    {
        ll a, k;
        cin >> a >> k; a--;
 
        if (depth[a] < k) cout << -1 << '\n';
        else cout << jmp(tbl, a, k)+1 << '\n';
    }
}