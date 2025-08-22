#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = a; i < (ll)(b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll) x.size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
ll inf = 1e18;
 
struct Node
{
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0, val = 0;
    Node(ll lo, ll hi) : lo(lo), hi(hi) {}
 
    Node(vll &v, ll lo, ll hi) : lo(lo), hi(hi)
    {
        if (lo + 1 < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
 
    ll query(ll L, ll R)
    {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
 
    void set(ll L, ll R, ll x)
    {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
        else
        {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
 
    void add(ll L, ll R, ll x)
    {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
        {
            if (mset != inf) mset += x;
            else madd += x;
            val += x;
        }
        else
        {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
 
    void push()
    {
        if (!l)
        {
            ll mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
 
        if (mset != inf) l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd) l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};
 
 
vll treeSize, order, indexOf;
 
void dfs(ll u, ll p, vector<vll> &adj)
{
    order.push_back(u);
    indexOf[u] = sz(order)-1;
 
    for (auto v : adj[u])
        if (v != p)
        {
            dfs(v, u, adj);
            treeSize[u] += treeSize[v];
        }
 
    treeSize[u] += 1;
}
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
 
    ll n, q;
    cin >> n >> q;
    vll a(n);
    indexOf.assign(n, 0);
    treeSize.assign(n, 0);
    rep(i, 0, n) cin >> a[i];
 
    vector<vll> adj(n);
    rep(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(0, -1, adj);
 
    // Setting up the LST
    Node st(0, n);
    rep (i, 0, n) st.add(i, i + treeSize[order[i]], a[order[i]]);
 
 
    ll op, s, x;
    while (q--)
    {
        cin >> op >> s;
        s--;
 
        if (op == 1)
        {
            cin >> x;
            st.add(indexOf[s], indexOf[s] + treeSize[s], x-a[s]);
            a[s] = x;
        }
 
        else cout << st.query(indexOf[s], indexOf[s]+1) << '\n';
    }
}