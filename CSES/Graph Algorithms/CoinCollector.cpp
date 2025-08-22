#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vll val, comp, z, cont;
ll Time, ncomps;
 
template <class G>
ll dfs(ll j, G &g)
{
    ll low = val[j] = ++Time, x;
    z.push_back(j);
    for (auto e : g[j])
        if (comp[e] < 0)
            low = min(low, val[e] ?: dfs(e, g));
    if (low == val[j])
    {
        do
        {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
 
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}
 
template <class G>
void scc(G &g)
{
    ll n = sz(g);
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g);
}
 
vll topoSort(const vector<vll> &gr)
{
    vll indeg(sz(gr)), q;
    for (auto &li : gr)
        for (int x : li)
            indeg[x]++;
    rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push_back(i);
    rep(j, 0, sz(q)) for (int x : gr[q[j]]) if (--indeg[x] == 0) q.push_back(x);
    return q;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vll a(n);
    rep(i, 0, n) cin >> a[i];
 
    vector<vll> adj(n);
    vector<pll> edges(m);
 
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[i] = {u, v};
 
        adj[u].push_back(v);
    }
 
    scc(adj);
    vector<vll> newAdj(ncomps);
 
 
    vll val(ncomps);
    rep (i, 0, n) val[comp[i]] += a[i];
    vll dp = val;
 
 
    for (auto e : edges)
    {
        if (comp[e.first] == comp[e.second]) continue;
        newAdj[comp[e.first]].push_back(comp[e.second]);
    }
 
    vll topo = topoSort(newAdj);
 
    for (auto x : topo)
        for (auto y : newAdj[x])
            dp[y] = max(dp[y], dp[x] + val[y]);
 
    cout << *max_element(all(dp)) << '\n';
}