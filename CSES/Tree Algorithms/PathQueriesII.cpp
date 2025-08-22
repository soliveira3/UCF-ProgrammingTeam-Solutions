#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ll> vi;
 
 
 
struct Tree
{
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; ll n;
	Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
	void set(ll pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(ll b, ll e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
 
 
template <bool VALS_EDGES>
struct HLD
{
    ll N, tim = 0;
    vector<vi> adj;
    vi par, siz, rt, pos;
    Tree tree;
    HLD(vector<vi> adj_) : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), rt(N), pos(N), tree(N, 0)
    {
        dfsSz(0);
        dfsHld(0);
    }
 
    void dfsSz(ll v)
    {
        for (ll &u : adj[v])
        {
            adj[u].erase(find(all(adj[u]), v));
            par[u] = v;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]])
                swap(u, adj[v][0]);
        }
    }
 
    void dfsHld(ll v)
    {
        pos[v] = tim++;
        for (ll u : adj[v])
        {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
 
    template <class B>
    void process(ll u, ll v, B op)
    {
        for (;; v = par[rt[v]])
        {
            if (pos[u] > pos[v]) swap(u, v);
            if (rt[u] == rt[v]) break;
            op(pos[rt[v]], pos[v] + 1);
        }
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
 
    void modifyPath(ll u, ll v, ll val)
    {
        process(u, v, [&](ll l, ll r) { tree.set(l, val); });
    }
 
    ll queryPath(ll u, ll v)
    { // Modify depending on problem
        ll res = -1e9;
        process(u, v, [&](ll l, ll r)
                { res = max(res, tree.query(l, r)); });
        return res;
    }
    ll querySubtree(ll v)
    { // modifySubtree is similar
        return tree.query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
    vll a(n);
    rep(i, 0, n) cin >> a[i];
 
    vector<vi> adj(n);
    rep(i, 0, n-1)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    HLD<false> hld(adj);
    rep(i, 0, n) hld.modifyPath(i, i, a[i]);
 
    ll op, x, y;
    while (q--)
    {
        cin >> op >> x >> y;
        x--; y--;
 
        if (op == 1) hld.modifyPath(x, x, y+1);
        else cout << hld.queryPath(x, y) << " ";
    }
 
    cout << '\n';
}