#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

struct UF {
	vll par, size;
	UF(ll n) : par(n, -1), size(n, 1) { iota(all(par), 0); }

	ll find(ll x) { return par[x] == x ? x : par[x] = find(par[x]); }

    bool join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (size[a] > size[b]) swap(a, b);
		size[a] += size[b]; par[b] = a;
		return true;
	}
};

struct ed { ll u, v, w; };
bool comp(ed a, ed b) { return a.w < b.w; }


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<ed> edges(m);
    vector<vector<ll>> adj(n);

    rep (i, 0, m) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
    }

    sort(all(edges), comp);
    UF dsu(n);
    vector<bool> goodEdge(m, false);
    rep (i, 0, m) {
        if (dsu.join(edges[i].u, edges[i].v)) {
            goodEdge[i] = true;
            adj[edges[i].u].push_back(edges[i].v);
            adj[edges[i].v].push_back(edges[i].u);
        }
    }


    

}