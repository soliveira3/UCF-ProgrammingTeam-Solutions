#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vll val, comp, z, cont;
int Time, ncomps;
template <class G>
int dfs(int j, G &g)
{
    int low = val[j] = ++Time, x;
    z.push_back(j);
 
    for (auto e : g[j])
        if (comp[e] < 0)
            low = min(low, (int)(val[e] ? val[e] : dfs(e, g)));
 
    if (low == val[j])
    {
        do
        {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        }
        while (x != j);
 
        cont.clear();
        ncomps++;
    }
 
    return val[j] = low;
}
 
template <class G>
void scc(G &g)
{
    int n = sz(g);
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g);
}
 
int main ()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vll> adj(n, vll());
    rep (i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
 
        adj[u].push_back(v);
    }
 
    scc(adj);
 
    cout << ncomps << '\n';
    rep (i, 0, n) cout << comp[i]+1 << " ";
    cout << '\n';
 
    return 0;
}