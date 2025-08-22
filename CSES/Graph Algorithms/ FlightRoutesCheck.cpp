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
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vll> adj(n);
 
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
 
    scc(adj);
 
    if (ncomps == 1) cout << "YES\n";
 
    else
    {
        cout << "NO\n";
 
        rep (i, 0, n)
        if (comp[i] != comp[0])
        {
            ll x = 1, y = i+1;
            if (comp[i] < comp[0]) swap(x, y);
            cout << x << " " << y << '\n';
            break;
        }
    }
}