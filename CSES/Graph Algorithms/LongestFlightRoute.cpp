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
 
    ll n, m;
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
    vll dist(n, LLONG_MIN);
    dist[0] = 0;
 
    rep (i, 0, n)
    {
        ll u = topo[i];
        for (auto v : adj[u])
            dist[v] = max(dist[v], dist[u] + 1LL);
    }
 
    // Impossible case
    if (dist[n-1] < 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    ll u = n-1;
    vll ans;
    while (u != 0)
    {
        ans.push_back(u);
        for (auto v : rev[u])
            if (dist[v] == dist[u]-1)
            {
                u = v;
                break;
            }
    }
 
    ans.push_back(0);
    reverse(all(ans));
 
    cout << sz(ans) << '\n';
    rep (i, 0, sz(ans)) cout << ans[i] + 1 << ' ';
    cout << '\n';
}