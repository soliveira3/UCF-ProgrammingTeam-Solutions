#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()
typedef long long ll;
typedef pair<long, long> pll;
typedef vector<ll> vll;
 
vll treeSz, tin, ind;
vector<vll> adj;
 
void dfs(ll u, ll p)
{
    ind[u] = tin.size();
    tin.push_back(u);
    for (auto v : adj[u])
        if (v != p)
        {
            dfs(v, u);
            treeSz[u] += treeSz[v];
        }
}
 
struct segTree
{
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
 
    vector<T> s; int n;
    segTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
 
    void update(int pos, T val)
    {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
 
    T query(int b, int e) // query [ b , e)
    {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2)
        {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
 
    vll values(n);
    rep(i, 0, n) cin >> values[i];
 
    ind.assign(n, -1);
    adj.assign(n, vll());
    treeSz.assign(n, 1);
 
    rep(i, 0, n-1)
    {
        ll u, v;
        cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(0, -1);
 
    segTree st(n);
    rep(i, 0, n) st.update(ind[i], values[i]);
 
    while (q--)
    {
        ll op; cin >> op;
        ll s, x;
 
        if (op == 1)
        {
            cin >> s >> x;
            st.update(ind[s-1], x);
        }
 
        else
        {
            cin >> s;
            s--;
            cout << st.query(ind[s], ind[s] + treeSz[s]) << '\n';
        }
    }
 
    return 0;
}