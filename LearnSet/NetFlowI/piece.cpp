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
struct edge { ll black, left, right; };


void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vll black, white;
    vector<edge> edges;

    rep (i, 0, n) cin >> grid[i];
    rep (i, 0, n) rep (j, 0, m)
    {
        ll pos = i*m + j;
        if (grid[i][j] == 'B')
        {
            black.push_back(pos);
            if ((i-1 >= 0 && grid[i-1][j] == 'W') && (j-1 >= 0 && grid[i][j-1] == 'W')) edges.push_back({pos, pos-m, pos-1}); // up left
            if ((j-1 >= 0 && grid[i][j-1] == 'W') && (i+1 < n && grid[i+1][j] == 'W')) edges.push_back({pos, pos-1, pos+m}); // left down
            if ((i+1 < n && grid[i+1][j] == 'W') && (j+1 >= 0 && grid[i][j+1] == 'W')) edges.push_back({pos, pos+m, pos+1}); // down right
            if ((j+1 >= 0 && grid[i][j+1] == 'W') && (i-1 >= 0 && grid[i-1][j] == 'W')) edges.push_back({pos, pos+1, pos-m}); // right up
        }

        else if (grid[i][j] == 'W') white.push_back(pos);
    }


    // Impossible case
    if (2*sz(black) != sz(white)) { cout << "NO\n"; return; }


    // RUNNING FLOW
    n = sz(black) + 2*sz(white);
    ll source = sz(black) + 2*sz(white), sink = source+1;
    Dinic dinic(n+2);

    // Adding source to black
    rep (i, 0, sz(black))
    {
        dinic.addEdge(source, i, 2);
        cout << source << " " << i << " 2\n";
    }
    // left to right
    rep (i, 0, sz(white))
    {
        dinic.addEdge(i+sz(black), i+sz(black)+sz(white), 1);
        cout << i+sz(black) << " " << i+sz(black)+sz(white) << " 1\n";
    }
    // Right to sink
    rep (i, 0, sz(white))
    {
        dinic.addEdge(i+sz(black)+sz(white), sink, 1);
        cout << i+sz(black)+sz(white) << " " << sink << " 1\n";
    }

    // Adding edges with coordinate compression for easier flow calculating
    sort(all(black));
    sort(all(white));

    for (auto e : edges)
    {
        ll b = lower_bound(all(black), e.black) - black.begin();
        ll l = lower_bound(all(white), e.left) - white.begin() + sz(black);
        ll r = lower_bound(all(white), e.right) - white.begin() + sz(black) + sz(white);

        cout << b << " " << l << " 2\n";
        cout << l << " " << r << " 1\n";

        dinic.addEdge(b, l, 2);
        dinic.addEdge(l, r, 1);
    }

    ll ans = dinic.calc(source, sink);
    cout << ans << '\n';
    cout << ((ans == sz(black)*2) ? "YES\n" : "NO\n");

    cout << '\n';
    rep (i, 0, n)
    {
        for (auto e : dinic.adj[i])
            if (e.flow())
                cout << i << " " << e.to << " " << e.flow() << "\n";
    }
}

/*
    UNSOLVED
*/

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll c; cin >> c;
    while (c--) solve();
}