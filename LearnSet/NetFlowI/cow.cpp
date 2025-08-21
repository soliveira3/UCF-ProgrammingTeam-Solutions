#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;


// kactl dinics for maxflow
struct Dinic {
	struct Edge {
		ll to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(ll a, ll b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(ll v, ll t, ll f) {
		if (v == t || !f) return f;
		for (ll& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(ll s, ll t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'll L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
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

struct line { ll x1, y1, x2, y2; };


void solve()
{
    ll x1, y1, x2, y2, n, source, sink;
    cin >> n;
    source = n; sink = n+1;

    vector<line> vert, hors;
    Dinic dinic(n+2);

    // INPUT
    rep(i, 0, n)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // Storing the index in the unused variable
        if (x1 == x2) vert.push_back({x1, y1, i, y2});
        else hors.push_back({x1, y1, x2, i});
    }

    // Adding source + sink edges
    rep (i, 0, sz(hors)) dinic.addEdge(source, hors[i].y2, 1);
    rep (i, 0, sz(vert)) dinic.addEdge(vert[i].x2, sink, 1);

    rep(i, 0, sz(hors)) rep(j, 0, sz(vert))
        if (hors[i].y1 >= min(vert[j].y1, vert[j].y2) && hors[i].y1 <= max(vert[j].y1, vert[j].y2) &&
            vert[j].x1 >= min(hors[i].x1, hors[i].x2) && vert[j].x1 <= max(hors[i].x1, hors[i].x2))
                dinic.addEdge(hors[i].y2, vert[j].x2, 1);

    // OUTPUT
    cout << n - dinic.calc(source, sink) << '\n';
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll c; cin >> c;
    while (c--) solve();
}