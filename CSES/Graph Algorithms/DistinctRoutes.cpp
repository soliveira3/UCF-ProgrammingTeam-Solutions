#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
struct Edge {
    ll to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); } // if you need flows
};
 
struct Dinic
{
	vll lvl, ptr, q, path;
	vector<vector<Edge>> adj;
 
    Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(ll a, ll b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
 
    ll dfs(ll v, ll t, ll f) {
		if (v == t || !f) return f;
		for (ll &i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))){
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
 
    ll calc(ll s, ll t)
    {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'll L=30' maybe faster for random data
			lvl = ptr = vll(sz(q));
			ll qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				ll v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
 
    bool leftOfMinCut(ll a) { return lvl[a] != 0; }
};
 
void dfs(ll s, ll t, Dinic &dinic, vll &path)
{
    path.push_back(s);
    if (s == t) return;
 
    for (auto &e : dinic.adj[s])
    {
        if (e.flow() > 0)
        {
            e.c = e.oc;
            dfs(e.to, t, dinic, path);
            return;
        }
    }
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, m, u, v;
    cin >> n >> m;
 
    Dinic dinic(n);
 
    rep (i, 0, m)
    {
        cin >> u >> v;
        u--; v--;
        dinic.addEdge(u, v, 1);
    }
 
    ll ans = dinic.calc(0, n-1);
    cout << ans << '\n';
 
    while (ans--)
    {
        vll path;
        dfs(0, n-1, dinic, path);
 
        cout << path.size() << '\n';
        for (auto x : path) cout << x+1 << " ";
        cout << '\n';
    }
 
    return 0;
}