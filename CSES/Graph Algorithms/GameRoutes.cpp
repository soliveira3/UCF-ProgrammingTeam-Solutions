#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
vll topoSort(const vector<vll>& gr)
{
	vll indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
 
    return q;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m, mod = 1e9+7;
    cin >> n >> m;
 
    vector<vll> adj(n), rev(n);
 
    rep (i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
 
    vll topo = topoSort(adj);
    vll numWays(n, 0);
    numWays[0] = 1;
 
    rep (i, 0, n)
    {
        ll u = topo[i];
        for (auto v : adj[u])
            numWays[v] = (numWays[v]+numWays[u]) % mod;
    }
 
    cout << numWays[n-1] << '\n';
}